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
 * @page about_types About types and type conversion
 *
 * The base::Type class template generates conversion code between javascript
 * values and C++ types. The base::Type::Cast() function converts a javascript
 * value to a pointer to a wrapped C++ type (if it exists) or returns zero. It
 * also converts a pointer to a C++ type or a C++ value to a wrapped javascript
 * object.
 *
 * To create custom conversions for bound classes, create a template
 * customization. For example:
 *
 * @code
 * namespace base {
 *   template<>
 *   class Type<MyType> {
 *		static MyType* Cast(v8::Handle<v8::Value> value) {
 *			// return an extracted MyType object
 *		}
 *		static v8::Handle<v8::Value> Cast(MyType& value) {
 *			return ClassDef<T>::WrapInstance(&value);
 *		}
 *   };
 * }
 * @endcode
 *
 * There are default specializations that handle conversions for the following types:
 *
 * - int
 * - unsigned int
 * - bool
 * - float
 * - double
 * - std::string
 * - std::vector containing any of the above types and pointers to bound classes
 *
 * Due to memory allocation issues, baseV8 cannot handle conversions to
 * const char* and char* (C-style strings). Thereforeplease use std::string for
 * string arguments.
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <vector>
#include <list>
#include "Common.h"

namespace base {
	/**
	 * Common Typedefs
	 */
	typedef unsigned int Size_t;
	#ifndef BASE_USEDOUBLE
		typedef float Real_t;
	#else
		typedef double Real_t;
	#endif
	typedef std::string String_t;
	typedef v8::Handle<v8::Value> JSValue_t;

	/*
	Forward declaration of base::ClassDef
	 */
	template <typename T> class ClassDef;

	/**
	 * @brief A class to define generic conversions between native types and
	 * javascript values
	 *
	 * This class can be used to create custom conversions. See @ref about_types
	 * for more information
	 */
	template <typename T>
	struct Type {
		typedef T ClassType;
		typedef T* ClassPtr;

		static ClassPtr Cast(v8::Handle<v8::Value> value) {
			// Use the base::ClassDef<>::Assert() function to verify that the value
			// is a wrapped instance of T
			if (ClassDef<T>::Assert(value)) {
				// force-cast the value into a javascript object
				v8::Handle<v8::Object> obj = value->ToObject();
				ClassPtr native_val;
				ExtractExternal((void**) &native_val, obj->GetInternalField(0));
				return native_val;
			}
			else {
				return 0;
			}
		}
		static v8::Handle<v8::Value> Cast(ClassPtr obj) {
			return ClassDef<T>::WrapInstance(obj);
		}
		static v8::Handle<v8::Value> Cast(ClassType& obj) {
			return ClassDef<T>::WrapInstance(&obj);
		}
	};

	/*
	 * Note: is the below specialization necessary? I believe not, but I can't
	 * recall why I wrote it in the first place (I completely paused all work on
	 * this project for ~6 months). Maybe I stumbled upon a bug that needed this
	 * to resolve. I plan to remove it, after verifying that it is not needed.
	 */
	template <>
	struct Type<void> {
		static void Cast(v8::Handle<v8::Value> value) {
			return;
		}
		static v8::Handle<v8::Value> Cast(void) {
			return v8::Undefined();
		}
	};

	template <>
	struct Type<int> {
		static int Cast(v8::Handle<v8::Value> value) {
			return value->Int32Value();
		}
		static v8::Handle<v8::Value> Cast(int obj) {
			return v8::Integer::New(obj);
		}
	};

	template <>
	struct Type<unsigned int> {
		static unsigned int Cast(v8::Handle<v8::Value> value) {
			return value->Uint32Value();
		}
		static v8::Handle<v8::Value> Cast(unsigned int obj) {
			return v8::Uint32::NewFromUnsigned(obj);
		}
	};

	template <>
	struct Type<bool> {
		static bool Cast(v8::Handle<v8::Value> value) {
			return value->BooleanValue();
		}
		static v8::Handle<v8::Value> Cast(bool obj) {
			return v8::Boolean::New(obj);
		}
	};

	template <>
	struct Type<float> {
		static float Cast(v8::Handle<v8::Value> value) {
			return static_cast<float>(value->ToNumber()->Value());
		}
		static v8::Handle<v8::Value> Cast(float obj) {
			return v8::Number::New(static_cast<double>(obj));
		}
	};

	template <>
	struct Type<double> {
		static double Cast(v8::Handle<v8::Value> value) {
			return value->ToNumber()->Value();
		}
		static v8::Handle<v8::Value> Cast(double obj) {
			return v8::Number::New(obj);
		}
	};

	template <>
	struct Type<String_t> {
		static String_t Cast(v8::Handle<v8::Value> value) {
			return String_t(*(v8::String::AsciiValue(value)));
		}
		static v8::Handle<v8::Value> Cast(String_t obj) {
			return v8::String::New(obj.c_str());
		}
	};

	template<typename T>
	struct Type<std::vector<T> > {
		typedef std::vector<T> Vector_t;

		static Vector_t Cast(v8::Handle<v8::Value> value) {
			Vector_t vec;
			if (value->IsArray()) {
				v8::Handle<v8::Array> array = v8::Handle<v8::Array>::Cast(value);
				for (size_t i = 0; i < array->Length(); i++)
					vec.push_back(array->CloneElementAt(i));
			}
			return vec;
		}
		static v8::Handle<v8::Value> Cast(Vector_t obj) {
			v8::Handle<v8::Array> array = v8::Array::New(obj.size());
			for (size_t i = 0; i < obj.size(); i++) {
				array->Set(i, Type<T>::Cast(obj[i]));
			}
			return array;
		}
	};

	template<>
	struct Type<JSValue_t> {
		static JSValue_t Cast(v8::Handle<v8::Value> value) {
			return value;
		}
	};
};

#endif /* TYPE_H_ */
