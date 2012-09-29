/*
Copyright (C) 2011 by Manolis Paterakis (http://media.opendesignstudio.gr)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
/**
 * @file
 * @brief Template structures for accessing class members
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
	struct MethodAccessors {
		typedef V (C::*GetterType) (void);
		typedef V (C::*GetterTypeC) (void);
		typedef void (C::*SetterType) (V);

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
		}
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
		}
	};

	template <typename C, typename V>
	struct PropAccessors {
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
		}
	};

	template <typename V>
	struct VarAccessors {
		static v8::Handle<v8::Value> Get(v8::Local<v8::String> property,
						const v8::AccessorInfo &info) {
			v8::Handle<v8::External> v = v8::Handle<v8::External>::Cast(info.Data());
			V* pVar = 0;
			ExtractExternal ((void**) &pVar, v);
			V value = *pVar;
			return Type<V>::Cast(value);
		}
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
		NativeAccessors<C, V>* pAcc =
			(NativeAccessors<C, V>*) Def::allocMember(sizeof(NativeAccessors<C, V>));
		pAcc->getter = getter;
		pAcc->setter = setter;
		int flags = 0;
		if (setter)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &MethodAccessors<C, V, false>::Get,
						   &MethodAccessors<C, V, false>::Set,
						   v8::External::New(pAcc),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	};

	template <typename C, typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V (C::*getter) () const,
					  void (C::*setter) (V) = 0) {
		NativeAccessors<C, V>* pAcc =
			(NativeAccessors<C, V>*) Def::allocMember(sizeof(NativeAccessors<C, V>));
		pAcc->getterC = getter;
		pAcc->setter = setter;
		int flags = 0;
		if (setter)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &MethodAccessors<C, V, true>::Get,
						   &MethodAccessors<C, V, true>::Set,
						   v8::External::New(pAcc),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	};

	template <typename C, typename V>
	void bindProperty(v8::Handle<v8::ObjectTemplate> templ,
					  const char* name,
					  V C::* var,
					  bool readonly = false) {
		NativeMember<C, V>* pMem =
			(NativeMember<C, V>*) Def::allocMember(sizeof(NativeMember<C, V>));
		pMem->mem = var;
		int flags = 0;
		if (!readonly)
			flags = v8::DontDelete;
		else
			flags = v8::DontDelete | v8::ReadOnly;
		templ->SetAccessor(v8::String::New(name),
						   &PropAccessors<C,V>::Get,
						   &PropAccessors<C,V>::Set,
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
						   &VarAccessors<V>::Get,
						   &VarAccessors<V>::Set,
						   v8::External::New(var),
						   v8::DEFAULT,
						   (v8::PropertyAttribute) flags);
	}
};

#endif /* PROPERTY_H_ */
