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
#ifndef CLASS_H_
#define CLASS_H_

#include <assert.h>
#include <string.h>/*
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
#ifndef CLASS_H_
#define CLASS_H_

#include <assert.h>
#include <string.h>
#include <vector>

#include "Common.h"
#include "Def.h"
#include "Constructor.h"
#include "Property.h"
#include "Function.h"
#include "Method.h"
#include "GMethod.h"
#include "Signatures.h"

namespace base {
	/**
	 * @brief Class used to generate all the glue code necessary to bind a native
	 * class to V8.
	 */
	template <typename C>
	class ClassDef : public Def {
	public:
		typedef C* (*ConstructorCallback) (const v8::Arguments&);
		/**
		 * @brief The signature of a callback function to be called every time an
		 * instance of this class is created in script code
		 * @see ClassDef::setInstanceCallback
		 * @param The newly created v8::Object
		 * @param The pointer to the native instance
		 */
		typedef void (*InstanceCallback) (v8::Persistent<v8::Object>, C*);

		/**
		 * @brief Bind a constructor signature. The actual constructor glue code
		 * will be generated automatically.
		 *
		 * This function can be used to bind more than one constructors for the same
		 * class. Use it with no template parameters to specify a default
		 * constructor. Example usage:
		 * \code
		 * base::ClassDef<MyType>("MyType")
		 *   .constructor()		// same as: .constructor<MyType* (void)>()
		 *   .constructor<MyType* (int, std::string)>()
		 *   // bind other members here
		 *   .bind();
		 * \endcode
		 *
		 * You can bind constructors that take up to nine (9) parameters.
		 * @return The class declaration to continue chained binding
		 */
		template<typename CF>
		ClassDef<C>& constructor() {
			CF* dummy = 0;
			m_constructors.push_back(createConstructor(dummy));
			return *this;
		}

		ClassDef<C>& constructor() {
			return constructor<C* (void)>();
		}

		/**
		 * @brief Bind a global function as a static member function
		 * @param name The name of the script-side method
		 * @param func The native global function to bind to
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& func(const char* name, F func) {
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetFunctionCallback(func),
										   v8::External::New(funcPtr),
										   GetFunctionSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a global function to be used as a method.
		 *
		 * First parameter type must be a pointer to class instance. The binded
		 * can take up to 8 parameters.
		 * @param name The name of the script-side method
		 * @param func A native global function in the form:
		 * @code RetType func(C*, ArgType0, ArgType1, ArgType2, ...) @endcode
		 *
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& gmethod(const char* name, F func) {
			// todo: Implement base::ClassDef::gmethod()
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetGlobalMethodCallback(func),
										   v8::External::New(funcPtr),
								   	   	   GetGlobalMethodSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a class method.
		 * @param name The name of the script-side method
		 * @param func The native method to bind to
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& method(const char* name, F func) {
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetMethodCallback(func),
										   v8::External::New(funcPtr),
										   GetMethodSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a property using native getter and setter member functions.
		 * @param name The name of the script-side propery
		 * @param getter The native getter method
		 * @param setter The native setter method
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& prop(const char* name,
						  V (C::*getter) (),
						  void (C::*setter) (V)) {
			bindProperty<C, V>(GetInstanceTmpl(), name, getter, setter);
			return *this;
		}
		template <typename V>
		ClassDef<C>& prop(const char* name,
						  V (C::*getter) () const,
						  void (C::*setter) (V)) {
			bindProperty<C, V>(GetInstanceTmpl(), name, getter, setter);
			return *this;
		}

		/**
		 * @brief Bind a native property field.
		 * @param name The name of the script-side property
		 * @param var The native property field
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& prop(const char* name, V C::*var) {
			bindProperty(GetInstanceTmpl(), name, var);
			return *this;
		}

		/**
		 * @brief Bind a global variable as a 'static' property of this class
		 * @param name The name of the script-side property
		 * @param var The native global variable
		 * @return Returns *this to enable chain-based binding
		 */

		template <typename V>
		ClassDef<C>& var(const char* name, V* var) {
			bindProperty(GetInstanceTmpl(), name, var);
			return *this;
		}

		/**
		 * @brief Bind a read-only property using a native getter method
		 * @param name The name of the script-side property
		 * @param getter The native getter method
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V (C::*getter) ()) {
			bindProperty(GetInstanceTmpl(), name, getter);
			return *this;
		}
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V (C::*getter) () const) {
			bindProperty(GetInstanceTmpl(), name, getter);
			return *this;
		}

		/**
		 * @brief Bind a native read-only property field
		 * @param name The name of the script-side property
		 * @param var The native property field
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V C::*var) {
			bindProperty(GetInstanceTmpl(), name, var, true);
			return *this;
		}

		/**
		 * @brief Bind a native read-only global variable as a 'static' property of this class
		 * @param name The name of the script-side property
		 * @param var The native global variable
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_var(const char* name, V* var) {
			bindProperty(GetInstanceTmpl(), name, var, true);
			return *this;
		}

		/**
		 * @brief Bind an integer constant
		 * @param name The name of the script-side constant
		 * @param value The integer value of the constant
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& enumr(const char* name, int value) {
			GetInstanceTmpl()->Set(name, v8::Integer::New(value));
			return *this;
		}

		/**
		 * @brief Inherit member bindings from a base class definition.
		 * The base class must be already bound.
		 * @return Returns *this to enable continuity of chain-based binding
		 */
		template <typename B>
		ClassDef<C>& inherit() {
			if (!ClassDef<B>::IsDefined())
				v8::ThrowException(FormatString("Class '%s': cannot inherit, base class not defined", GetName()));
			GetFunctionTmpl()->Inherit(ClassDef<B>::GetFunctionTmpl());
		}

		/**
		 * @brief Specify a callback function to be called every time an instance of this class is created on the script side.
		 * @param instFunc The function callback @see InstanceCallback
		 * @return Returns *this to enable continuity of chain-based binding
		 */
		ClassDef<C>& setInstanceCallback(InstanceCallback instFunc) {
			m_InstanceCallback = instFunc;
			return *this;
		}

		/**
		 * @brief Binds the class definition to an object template.
		 *
		 * This function must be the last call to a chain of binding calls, as it closes the class definition and binds to the
		 * specified template. Example usage:
	 	 * \code
		 * base::ClassDef<MyType>("MyType")
		 *   // make some binding calls
		 *   .bindTo();
		 * \endcode
		 *
		 * @param obj The object template of which the class constructor function will be a member. If ommitted it binds the
		 * it to the global object of the currently active context.
		 */
		void bindTo(Def def = Def()) {
			v8::Handle<v8::ObjectTemplate> obj = def.getTemplate();
			m_isDefined = true;
			if (obj.IsEmpty()) {
				if (!v8::Context::InContext())
					v8::ThrowException(FormatString("must be in a context to define Class '%s'", GetName()));
				v8::Context::GetCurrent()->Global()->Set(v8::String::New(GetName()), GetFunctionTmpl()->GetFunction());
			}
			else
				obj->Set(v8::String::New(GetName()), GetFunctionTmpl()->GetFunction());

		}

		/**
		 * @brief Class constructor. It essentialy inititalises the class binding procedure.
		 * @param name The of the class function constructor on the script side
		 */
		ClassDef(const char* name) {
			m_funcTempl = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(&CtorCallback));
			m_instTempl = m_funcTempl->InstanceTemplate();
			m_protoTempl = m_funcTempl->PrototypeTemplate();
			m_instTempl->SetInternalFieldCount(1);
			m_name = name;
			m_funcTempl->SetClassName(v8::String::New(m_name.c_str()));
		}

		/**
		 * @brief Retrieve the function template of the class constructor function.
		 *
		 * Returns empty handle if class is not defined.
		 */
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() {
			return (IsDefined() ? m_funcTempl : v8::Handle<v8::FunctionTemplate>());
		};
		/**
		 * @brief Retrieve the instance template.
		 *
		 * Returns empty handle if class is not defined
		 */
		static v8::Handle<v8::ObjectTemplate> GetInstanceTmpl() { return m_instTempl; };
		/**
		 * @brief Retrieve the prototype template
		 *
		 * Returns empty handle if class is not defined
		 */
		static v8::Handle<v8::ObjectTemplate> GetPrototypeTmpl() { return m_protoTempl; };
		static const char* GetName() { return m_name.c_str(); };
		/**
		 * @brief Wrap a pre-existing instance of a native object to a JS object.
		 *
		 * @param native_obj A pointer the native object instance
		 * @return A persistent handle to the JS object instance
		 */
		static v8::Persistent<v8::Object> WrapInstance(C* native_obj) {
			v8::Persistent<v8::Object> jsp_obj = IsDefined()?							// if class is defined,
					v8::Persistent<v8::Object>::New(GetInstanceTmpl()->NewInstance()) :	// use the built-in instance template
					v8::Persistent<v8::Object>::New(v8::Object::New());					// otherwise, use a generic template.
			jsp_obj->SetInternalField(0, v8::External::New(native_obj));
			return jsp_obj;
		}
		/**
		 * @brief Determine whether a native class is defined (binded) through baseV8
		 *
		 * @return Returns true if the class has been binded through the base::ClassDef::bind method
		 */
		static bool IsDefined() { return m_isDefined; };
		/**
		 * @brief Assert that an object is a wrapped instance of this class
		 *
		 * @return Returns true if the javascript value is a wrapped instance of class T
		 */
		static bool Assert(v8::Handle<v8::Value> value) {
			// Verify that the value is an object and that its constructor function
			// name is this class definition name.
			if (value->IsObject()) {
				v8::String::AsciiValue ctr_name(value->ToObject()->GetConstructorName());
				if (strcmp(ctr_name, GetName()) == 0) {
					return true;
				}
			}
			return false;
		};

		v8::Handle<v8::ObjectTemplate> getTemplate() {
			return GetInstanceTmpl();
		};

	protected:
		static v8::Handle<v8::Value> CtorCallback(const v8::Arguments& args) {
			v8::Persistent<v8::Object> jsp_obj(v8::Persistent<v8::Object>::New(args.This()));
			C* native_obj = 0;

			v8::String::AsciiValue callee_str(args.Callee()->GetName()->ToString());
			if(!m_constructors.size())
				return v8::ThrowException(FormatString("Class '%s': cannot instantiate, no constructors defined", *callee_str));

			if(!args.IsConstructCall())
				return v8::ThrowException(FormatString("%s(): illegal constructor call as a normal function", *callee_str));

			typename ConstructorList::iterator pConstr = m_constructors.begin();
			while (pConstr != m_constructors.end()) {
				ConstructorCallback call = *pConstr;
				native_obj = call(args);
				if (native_obj)
					break;
				pConstr++;
			}
			if (native_obj == 0)
				return v8::ThrowException(FormatString("%s(): no matching constructor for %d arguments",
													   *callee_str, args.Length()));
			else {
				jsp_obj.MakeWeak(native_obj, DtorCallback);
				jsp_obj->SetInternalField(0, v8::External::New(native_obj));
				if (m_InstanceCallback)
					m_InstanceCallback(jsp_obj, native_obj);
			}
			return jsp_obj;
		};

		static void DtorCallback(v8::Persistent<v8::Value> handle, void* data) {
			assert(data);
			C* obj = (C*) (data);
			assert(obj);
			delete obj;
			handle.Dispose();
			handle.Clear();
		};

	private:
		static v8::Persistent<v8::FunctionTemplate> m_funcTempl;
		static v8::Handle<v8::ObjectTemplate> m_instTempl;
		static v8::Handle<v8::ObjectTemplate> m_protoTempl;
		typedef std::vector<ConstructorCallback> ConstructorList;
		static ConstructorList m_constructors;
		static std::string m_name;
		static bool m_isDefined;
		static size_t m_numMembers;
		static InstanceCallback m_InstanceCallback;
	};

	template <typename C> v8::Persistent<v8::FunctionTemplate> ClassDef<C>::m_funcTempl;
	template <typename C> v8::Handle<v8::ObjectTemplate> ClassDef<C>::m_instTempl;
	template <typename C> v8::Handle<v8::ObjectTemplate> ClassDef<C>::m_protoTempl;
	template <typename C> std::vector<typename ClassDef<C>::ConstructorCallback> ClassDef<C>::m_constructors;
	template <typename C> std::string ClassDef<C>::m_name;
	template <typename C> bool ClassDef<C>::m_isDefined = false;
	template <typename C> size_t ClassDef<C>::m_numMembers = 0;
	template <typename C> typename ClassDef<C>::InstanceCallback ClassDef<C>::m_InstanceCallback = 0;

	/*
	 * Specializations
	 */
	template <>
	class ClassDef<void> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return false;	}

	};

	template <>
	class ClassDef<int> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsInt32(); }
	};

	template <>
	class ClassDef<unsigned int> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsUint32();	}
	};

	template <>
	class ClassDef<bool> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsBoolean(); }
	};

	template <>
	class ClassDef<float> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsNumber(); }
	};

	template <>
	class ClassDef<double> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsNumber(); }
	};

	template <>
	class ClassDef<String_t> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsString(); }
	};

	template <typename T>
	class ClassDef<std::vector<T> > {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsArray(); }
	};

	template <>
	class ClassDef<JSValue_t> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return true; }
	};
};

#endif /* CLASS_H_ */


#include <vector>

#include "Common.h"
#include "Type.h" 				// this is probably not needed
#include "Def.h"
#include "Constructor.h"
#include "Property.h"
#include "Function.h"
#include "Method.h"
#include "GMethod.h"
#include "Signatures.h"

namespace base {
	/**
	 * @brief Class used to generate all the glue code necessary to bind a native class to V8.
	 */
	template <typename C>
	class ClassDef : public Def {
	public:
		typedef C* (*ConstructorCallback) (const v8::Arguments&);
		/**
		 * @brief The signature of a callback function to be called every time an instance of this class is created in script code
		 * @see ClassDef::setInstanceFunc
		 * @param The newly created v8::Object
		 * @param The pointer to the native instance
		 */
		typedef void (*InstanceFunc) (v8::Persistent<v8::Object>, C*);

		/**
		 * @brief Bind a constructor signature. The actual constructor glue code will be generated automatically.
		 *
		 * This function can be used to bind more than one constructors for the same
		 * class. Use it with no template parameters to specify a default
		 * constructor. Example usage:
		 * \code
		 * base::ClassDef<MyType>("MyType")
		 *   .constructor()		// same as: .constructor<MyType* (void)>()
		 *   .constructor<MyType* (int, std::string)>()
		 *   // bind other members here
		 *   .bind();
		 * \endcode
		 *
		 * You can bind constructors that take up to nine (9) parameters.
		 * @return The class declaration to continue chained binding
		 */
		template<typename CF>
		ClassDef<C>& constructor() {
			CF* dummy = 0;
			m_constructors.push_back(createConstructor(dummy));
			return *this;
		}

		ClassDef<C>& constructor() {
			return constructor<C* (void)>();
		}

		/**
		 * @brief Bind a global function as a static member function
		 * @param name The name of the script-side method
		 * @param func The native global function to bind to
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& func(const char* name, F func) {
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetFunctionCallback(func),
										   v8::External::New(funcPtr),
										   GetFunctionSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a global function to be used as a method.
		 *
		 * First parameter type must be a pointer to class instance.
		 * @param name The name of the script-side method
		 * @param func A native global function in the form: /code RetType func(C*, ArgType0 a0, ArgType1 a1, ArgType2 a2, ...) /endcode
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& gmethod(const char* name, F func) {
			// todo: Implement base::ClassDef::gmethod()
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetGlobalMethodCallback(func),
										   v8::External::New(funcPtr),
								   	   	   GetGlobalMethodSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a class method.
		 * @param name The name of the script-side method
		 * @param func The native method to bind to
		 * @return Returns *this to enable chain-based binding
		 */
		template<typename F>
		ClassDef<C>& method(const char* name, F func) {
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			GetInstanceTmpl()->Set(v8::String::New(name),
								   v8::FunctionTemplate::New(
										   GetMethodCallback(func),
										   v8::External::New(funcPtr),
										   GetMethodSignature(func)),
								   (v8::PropertyAttribute) flags);
			return *this;
		}

		/**
		 * @brief Bind a property using native getter and setter member functions.
		 * @param name The name of the script-side propery
		 * @param getter The native getter method
		 * @param setter The native setter method
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& prop(const char* name,
						  V (C::*getter) (),
						  void (C::*setter) (V)) {
			bindProperty<C, V>(GetInstanceTmpl(), name, getter, setter);
			return *this;
		}
		template <typename V>
		ClassDef<C>& prop(const char* name,
						  V (C::*getter) () const,
						  void (C::*setter) (V)) {
			bindProperty<C, V>(GetInstanceTmpl(), name, getter, setter);
			return *this;
		}

		/**
		 * @brief Bind a native property field.
		 * @param name The name of the script-side property
		 * @param var The native property field
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& prop(const char* name, V C::*var) {
			bindProperty(GetInstanceTmpl(), name, var);
			return *this;
		}

		/**
		 * @brief Bind a global variable as a 'static' property of this class
		 * @param name The name of the script-side property
		 * @param var The native global variable
		 * @return Returns *this to enable chain-based binding
		 */

		template <typename V>
		ClassDef<C>& var(const char* name, V* var) {
			bindProperty(GetInstanceTmpl(), name, var);
			return *this;
		}

		/**
		 * @brief Bind a read-only property using a native getter method
		 * @param name The name of the script-side property
		 * @param getter The native getter method
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V (C::*getter) ()) {
			bindProperty(GetInstanceTmpl(), name, getter);
			return *this;
		}
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V (C::*getter) () const) {
			bindProperty(GetInstanceTmpl(), name, getter);
			return *this;
		}

		/**
		 * @brief Bind a native read-only property field
		 * @param name The name of the script-side property
		 * @param var The native property field
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_prop(const char* name, V C::*var) {
			bindProperty(GetInstanceTmpl(), name, var, true);
			return *this;
		}

		/**
		 * @brief Bind a native read-only global variable as a 'static' property of this class
		 * @param name The name of the script-side property
		 * @param var The native global variable
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& readonly_var(const char* name, V* var) {
			bindProperty(GetInstanceTmpl(), name, var, true);
			return *this;
		}

		/**
		 * @brief Bind an integer constant
		 * @param name The name of the script-side constant
		 * @param value The integer value of the constant
		 * @return Returns *this to enable chain-based binding
		 */
		template <typename V>
		ClassDef<C>& enumr(const char* name, int value) {
			GetInstanceTmpl()->Set(name, v8::Integer::New(value));
			return *this;
		}

		/**
		 * @brief Inherit member bindings from a base class definition.
		 * The base class must be already bound.
		 * @return Returns *this to enable continuity of chain-based binding
		 */
		template <typename B>
		ClassDef<C>& inherit() {
			if (!ClassDef<B>::IsDefined())
				v8::ThrowException(FormatString("Class '%s': cannot inherit, base class not defined", GetName()));
			GetFunctionTmpl()->Inherit(ClassDef<B>::GetFunctionTmpl());
		}

		/**
		 * @brief Specify a callback function to be called every time an instance of this class is created on the script side.
		 * @param instFunc The function callback @see InstanceFunc
		 * @return Returns *this to enable continuity of chain-based binding
		 */
		ClassDef<C>& setInstanceFunc(InstanceFunc instFunc) {
			m_instanceFunc = instFunc;
			return *this;
		}

		/**
		 * @brief Binds the class definition to an object template.
		 *
		 * This function must be the last call to a chain of binding calls, as it closes the class definition and binds to the
		 * specified template. Example usage:
	 	 * \code
		 * base::ClassDef<MyType>("MyType")
		 *   // make some binding calls
		 *   .bindTo();
		 * \endcode
		 *
		 * @param obj The object template of which the class constructor function will be a member. If ommitted it binds the
		 * it to the global object of the currently active context.
		 */
		void bindTo(Def def = Def()) {
			v8::Handle<v8::ObjectTemplate> obj = def.getTemplate();
			m_isDefined = true;
			if (obj.IsEmpty()) {
				if (!v8::Context::InContext())
					v8::ThrowException(FormatString("must be in a context to define Class '%s'", GetName()));
				v8::Context::GetCurrent()->Global()->Set(v8::String::New(GetName()), GetFunctionTmpl()->GetFunction());
			}
			else
				obj->Set(v8::String::New(GetName()), GetFunctionTmpl()->GetFunction());

		}

		/**
		 * @brief Class constructor. It essentialy inititalises the class binding procedure.
		 * @param name The of the class function constructor on the script side
		 */
		ClassDef(const char* name) {
			m_funcTempl = v8::Persistent<v8::FunctionTemplate>::New(v8::FunctionTemplate::New(&CtorCallback));
			m_instTempl = m_funcTempl->InstanceTemplate();
			m_protoTempl = m_funcTempl->PrototypeTemplate();
			m_instTempl->SetInternalFieldCount(1);
			m_name = name;
			m_funcTempl->SetClassName(v8::String::New(m_name.c_str()));
		}

		/**
		 * @brief Retrieve the function template of the class constructor function.
		 *
		 * Returns empty handle if class is not defined.
		 */
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() {
			return (IsDefined() ? m_funcTempl : v8::Handle<v8::FunctionTemplate>());
		};
		/**
		 * @brief Retrieve the instance template.
		 *
		 * Returns empty handle if class is not defined
		 */
		static v8::Handle<v8::ObjectTemplate> GetInstanceTmpl() { return m_instTempl; };
		/**
		 * @brief Retrieve the prototype template
		 *
		 * Returns empty handle if class is not defined
		 */
		static v8::Handle<v8::ObjectTemplate> GetPrototypeTmpl() { return m_protoTempl; };
		static const char* GetName() { return m_name.c_str(); };
		/**
		 * @brief Wrap a pre-existing instance of a native object to a JS object.
		 *
		 * @param native_obj A pointer the native object instance
		 * @return A persistent handle to the JS object instance
		 */
		static v8::Persistent<v8::Object> WrapInstance(C* native_obj) {
			v8::Persistent<v8::Object> jsp_obj = IsDefined()?							// if class is defined,
					v8::Persistent<v8::Object>::New(GetInstanceTmpl()->NewInstance()) :	// use the built-in instance template
					v8::Persistent<v8::Object>::New(v8::Object::New());					// otherwise, use a generic template.
			jsp_obj->SetInternalField(0, v8::External::New(native_obj));
			return jsp_obj;
		}
		/**
		 * @brief Determine whether a native class is defined (binded) through baseV8
		 *
		 * @return Returns true if the class has been binded through the base::ClassDef::bind method
		 */
		static bool IsDefined() { return m_isDefined; };
		/**
		 * @brief Assert that an object is a wrapped instance of this class
		 *
		 * @return Returns true if the javascript value is a wrapped instance of class T
		 */
		static bool Assert(v8::Handle<v8::Value> value) {
			// Verify that the value is an object and that its constructor function
			// name is this class definition name.
			if (value->IsObject()) {
				v8::String::AsciiValue ctr_name(value->ToObject()->GetConstructorName());
				if (strcmp(ctr_name, GetName()) == 0) {
					return true;
				}
			}
			return false;
		};

		v8::Handle<v8::ObjectTemplate> getTemplate() {
			return GetInstanceTmpl();
		};

	protected:
		static v8::Handle<v8::Value> CtorCallback(const v8::Arguments& args) {
			v8::Persistent<v8::Object> jsp_obj(v8::Persistent<v8::Object>::New(args.This()));
			C* native_obj = 0;

			v8::String::AsciiValue callee_str(args.Callee()->GetName()->ToString());
			if(!m_constructors.size())
				return v8::ThrowException(FormatString("Class '%s': cannot instantiate, no constructors defined", *callee_str));

			if(!args.IsConstructCall())
				return v8::ThrowException(FormatString("%s(): illegal constructor call as a normal function", *callee_str));

			typename ConstructorList::iterator pConstr = m_constructors.begin();
			while (pConstr != m_constructors.end()) {
				ConstructorCallback call = *pConstr;
				native_obj = call(args);
				if (native_obj)
					break;
				pConstr++;
			}
			if (native_obj == 0)
				return v8::ThrowException(FormatString("%s(): no matching constructor for %d arguments",
													   *callee_str, args.Length()));
			else {
				jsp_obj.MakeWeak(native_obj, DtorCallback);
				jsp_obj->SetInternalField(0, v8::External::New(native_obj));
				if (m_instanceFunc)
					m_instanceFunc(jsp_obj, native_obj);
			}
			return jsp_obj;
		};

		static void DtorCallback(v8::Persistent<v8::Value> handle, void* data) {
			assert(data);
			C* obj = (C*) (data);
			assert(obj);
			delete obj;
			handle.Dispose();
			handle.Clear();
		};

	private:
		static v8::Persistent<v8::FunctionTemplate> m_funcTempl;
		static v8::Handle<v8::ObjectTemplate> m_instTempl;
		static v8::Handle<v8::ObjectTemplate> m_protoTempl;
		typedef std::vector<ConstructorCallback> ConstructorList;
		static ConstructorList m_constructors;
		static std::string m_name;
		static bool m_isDefined;
		static size_t m_numMembers;
		static InstanceFunc m_instanceFunc;
	};

	template <typename C> v8::Persistent<v8::FunctionTemplate> ClassDef<C>::m_funcTempl;
	template <typename C> v8::Handle<v8::ObjectTemplate> ClassDef<C>::m_instTempl;
	template <typename C> v8::Handle<v8::ObjectTemplate> ClassDef<C>::m_protoTempl;
	template <typename C> std::vector<typename ClassDef<C>::ConstructorCallback> ClassDef<C>::m_constructors;
	template <typename C> std::string ClassDef<C>::m_name;
	template <typename C> bool ClassDef<C>::m_isDefined = false;
	template <typename C> size_t ClassDef<C>::m_numMembers = 0;
	template <typename C> typename ClassDef<C>::InstanceFunc ClassDef<C>::m_instanceFunc = 0;

	/*
	 * Specializations
	 */
	template <>
	class ClassDef<void> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return false;	}

	};

	template <>
	class ClassDef<int> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsInt32(); }
	};

	template <>
	class ClassDef<unsigned int> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsUint32();	}
	};

	template <>
	class ClassDef<bool> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsBoolean(); }
	};

	template <>
	class ClassDef<float> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsNumber(); }
	};

	template <>
	class ClassDef<double> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsNumber(); }
	};

	template <>
	class ClassDef<String_t> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsString(); }
	};

	template <typename T>
	class ClassDef<std::vector<T> > {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return value->IsArray(); }
	};

	template <>
	class ClassDef<JSValue_t> {
	public:
		static v8::Handle<v8::FunctionTemplate> GetFunctionTmpl() { return v8::Handle<v8::FunctionTemplate>(); }
		static bool Assert(v8::Handle<v8::Value> value) { return true; }
	};
};

#endif /* CLASS_H_ */
