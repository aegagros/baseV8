/*
 * Property.h
 *
 *  Created on: 10 Νοε 2011
 *      Author: manolis
 */

#ifndef PROPERTY_H_
#define PROPERTY_H_

#include "Type.h"

namespace base {

	template <typename C, typename V>
	struct NativeAccessors {
		V (C::*getter) ();
		V (C::*getterC) () const;
		void (C::*setter) (V);

		NativeAccessors(V (C::*g) (), void (C::*s) (V))
			: getter(g), setter(s) {};
		NativeAccessors(V (C::*g) () const, void (C::*s) (V))
			: getterC(g), setter(s) {};
	};

	template <typename C, typename V>
	struct NativeMember {
		V C::* mem;

		NativeMember(V C::*m) : mem(m) {};
	};

	template <typename C, typename V, bool Const>
	struct MethodGetter {
		typedef V (C::*GetterType) (void);
		typedef V (C::*GetterTypeC) (void);

		static v8::Handle<v8::Value> Get(v8::Local<v8::String> property,
										const v8::AccessorInfo &info) {
			v8::Handle<v8::External> g = v8::Handle<v8::External>::Cast(info.Data());
			NativeAccessors<C, V>* pAcc = 0;
			ExtractExternal((void**)&pAcc, g);

			v8::Handle<v8::Object> self = info.This();
			C* obj = Type<C>::Cast(self);
			V val;
			if (Const)
				val = (obj->*(pAcc->getterC)) ();
			else
				val = (obj->*(pAcc->getter)) ();
			return Type<V>::Cast(val);
		};
	};

	template <typename C, typename V>
	struct MethodSetter {
		typedef void (C::*SetterType) (V);
		static void Set(v8::Local<v8::String> property,
						v8::Local<v8::Value> value,
						const v8::AccessorInfo &info) {

			v8::Handle<v8::External> s = v8::Handle<v8::External>::Cast(info.Data());
			NativeAccessors<C, V>* pAcc = 0;
			ExtractExternal((void**)&pAcc, s);
			SetterType setFunc = pAcc->setter;

			v8::Handle<v8::Object> self = info.This();
			C* obj = Type<C>::Cast(self);
			V native_value = Type<V>::Cast(value);
			(obj->*setFunc) (native_value);
		};
	};

	template <typename C, typename V>
	struct PropGetter {
		static v8::Handle<v8::Value> Get(v8::Local<v8::String> property,
										const v8::AccessorInfo &info) {
			v8::Handle<v8::External> m = v8::Handle<v8::External>::Cast(info.Data());
			NativeMember<C, V>* pMem = 0;
			ExtractExternal((void**)&pMem, m);
			V C::* mem = pMem->mem;

			v8::Handle<v8::Object> self = info.This();
			C* obj = Type<C>::Cast(self);
			V val = obj->*mem;
			return Type<V>::Cast(val);
		}
	};

	template <typename C, typename V>
	struct PropSetter {
		static void Set(v8::Local<v8::String> property,
						v8::Local<v8::Value> value,
						const v8::AccessorInfo &info) {
			v8::Handle<v8::External> m = v8::Handle<v8::External>::Cast(info.Data());
			NativeMember<C, V>* pMem = 0;
			ExtractExternal((void**)&pMem, m);
			V C::* mem = pMem->mem;

			v8::Handle<v8::Object> self = info.This();
			C* obj = Type<C>::Cast(self);
			V native_value = Type<V>::Cast(value);
			obj->*mem = native_value;
		};
	};

	template <typename V>
	struct VarGetter {
		static v8::Handle<v8::Value> Get(v8::Local<v8::String> property,
						const v8::AccessorInfo &info) {
			v8::Handle<v8::External> v = v8::Handle<v8::External>::Cast(info.Data());
			V* pVar = 0;
			ExtractExternal ((void**) &pVar, v);
			V value = *pVar;
			return Type<V>::Cast(value);
		}
	};

	template <typename V>
	struct VarSetter {
		static void Set(v8::Local<v8::String> property,
						v8::Local<v8::Value> value,
						const v8::AccessorInfo &info) {
			v8::Handle<v8::External> v = v8::Handle<v8::External>::Cast(info.Data());
			V* pVar = 0;
			ExtractExternal((void**)&pVar, v);

			V native_value = Type<V>::Cast(value);
			*pVar = native_value;
		}
	};


	template <typename C, typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V (C::*getter) (),
					  void (C::*setter) (V) = 0) {
		/* todo: use a smartptr or a memory pool to avoid memory leaks here */
		//NativeAccessors<C, V>* pAcc = new NativeAccessors<C, V>(getter, setter);
		NativeAccessors<C, V>* pAcc = (NativeAccessors<C, V>*) Def::allocMember(sizeof(NativeAccessors<C, V>));
		pAcc->getter = getter;
		pAcc->setter = setter;
		int flags = 0;
		if (setter)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &MethodGetter<C, V, false>::Get,
						   &MethodSetter<C, V>::Set,
						   v8::External::New(pAcc),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	};

	template <typename C, typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V (C::*getter) () const,
					  void (C::*setter) (V) = 0) {
		/* todo: use a smartptr or a memory pool to avoid memory leaks here */
		//NativeAccessors<C, V>* pAcc = new NativeAccessors<C, V>(getter, setter);
		NativeAccessors<C, V>* pAcc = (NativeAccessors<C, V>*) Def::allocMember(sizeof(NativeAccessors<C, V>));
		pAcc->getterC = getter;
		pAcc->setter = setter;
		int flags = 0;
		if (setter)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &MethodGetter<C, V, true>::Get,
						   &MethodSetter<C, V>::Set,
						   v8::External::New(pAcc),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	};

	template <typename C, typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V C::* var,
					  bool readonly = false) {
		/* todo: use a smartptr or a memory pool to avoid memory leaks here */
		//NativeMember<C, V>* pMem = new NativeMember<C, V> (var);
		NativeMember<C, V>* pMem = (NativeMember<C, V>*) Def::allocMember(sizeof(NativeMember<C, V>));
		pMem->mem = var;
		int flags = 0;
		if (!readonly)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &PropGetter<C,V>::Get,
						   &PropSetter<C,V>::Set,
						   v8::External::New(pMem),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	}

	template <typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V* var,
					  bool readonly = false) {
		int flags = 0;
		if (!readonly)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &VarGetter<V>::Get,
						   &VarSetter<V>::Set,
						   v8::External::New(var),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	}
};

#endif /* PROPERTY_H_ */
