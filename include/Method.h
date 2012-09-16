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
#ifndef METHOD_H_
#define METHOD_H_
#include "Type.h"
#include "Common.h"

namespace base {
	template<typename C, typename R>
	struct Method {
		static v8::Handle<v8::Value> Func0(const v8::Arguments& args) {
			typedef R (C::*M)();
			ASSERT_PARAM_COUNT_THROW(args, 0);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			R ret_val = (obj->*method)();
			return Type<R>::Cast(ret_val);
		}
		template<typename A0>
		static v8::Handle<v8::Value> Func1(const v8::Arguments& args) {
			typedef R (C::*M)(A0);
			ASSERT_PARAM_COUNT_THROW(args, 1);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			R ret_val = (obj->*method)(a0);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1>
		static v8::Handle<v8::Value> Func2(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1);
			ASSERT_PARAM_COUNT_THROW(args, 2);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			R ret_val = (obj->*method)(a0, a1);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2>
		static v8::Handle<v8::Value> Func3(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2);
			ASSERT_PARAM_COUNT_THROW(args, 3);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			R ret_val = (obj->*method)(a0, a1, a2);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3>
		static v8::Handle<v8::Value> Func4(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3);
			ASSERT_PARAM_COUNT_THROW(args, 4);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			R ret_val = (obj->*method)(a0, a1, a2, a3);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4>
		static v8::Handle<v8::Value> Func5(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3, A4);
			ASSERT_PARAM_COUNT_THROW(args, 5);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			R ret_val = (obj->*method)(a0, a1, a2, a3, a4);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5>
		static v8::Handle<v8::Value> Func6(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3, A4, A5);
			ASSERT_PARAM_COUNT_THROW(args, 6);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			R ret_val = (obj->*method)(a0, a1, a2, a3, a4, a5);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6>
		static v8::Handle<v8::Value> Func7(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3, A4, A5, A6);
			ASSERT_PARAM_COUNT_THROW(args, 7);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			R ret_val = (obj->*method)(a0, a1, a2, a3, a4, a5, a6);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6, typename A7>
		static v8::Handle<v8::Value> Func8(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3, A4, A5, A6, A7);
			ASSERT_PARAM_COUNT_THROW(args, 8);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			R ret_val = (obj->*method)(a0, a1, a2, a3, a4, a5, a6, a7);
			return Type<R>::Cast(ret_val);
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6, typename A7, typename A8>
		static v8::Handle<v8::Value> Func9(const v8::Arguments& args) {
			typedef R (C::*M)(A0, A1, A2, A3, A4, A5, A6, A7, A8);
			ASSERT_PARAM_COUNT_THROW(args, 9);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			A8 a8 = Type<A8>::Cast(args[8]);
			R ret_val = (obj->*method)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
			return Type<R>::Cast(ret_val);
		}
	};

	template <typename C>
	struct Method<C, void> {
		static v8::Handle<v8::Value> Func0(const v8::Arguments& args) {
			typedef void (C::*M)();
			ASSERT_PARAM_COUNT_THROW(args, 0);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			(obj->*method)();
			return v8::Undefined();
		}
		template<typename A0>
		static v8::Handle<v8::Value> Func1(const v8::Arguments& args) {
			typedef void (C::*M)(A0);
			ASSERT_PARAM_COUNT_THROW(args, 1);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			(obj->*method)(a0);
			return v8::Undefined();
		}
		template<typename A0, typename A1>
		static v8::Handle<v8::Value> Func2(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1);
			ASSERT_PARAM_COUNT_THROW(args, 2);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			(obj->*method)(a0, a1);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2>
		static v8::Handle<v8::Value> Func3(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2);
			ASSERT_PARAM_COUNT_THROW(args, 3);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			(obj->*method)(a0, a1, a2);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3>
		static v8::Handle<v8::Value> Func4(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3);
			ASSERT_PARAM_COUNT_THROW(args, 4);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			(obj->*method)(a0, a1, a2, a3);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4>
		static v8::Handle<v8::Value> Func5(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3, A4);
			ASSERT_PARAM_COUNT_THROW(args, 5);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			(obj->*method)(a0, a1, a2, a3, a4);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5>
		static v8::Handle<v8::Value> Func6(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3, A4, A5);
			ASSERT_PARAM_COUNT_THROW(args, 6);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			(obj->*method)(a0, a1, a2, a3, a4, a5);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6>
		static v8::Handle<v8::Value> Func7(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3, A4, A5, A6);
			ASSERT_PARAM_COUNT_THROW(args, 7);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			(obj->*method)(a0, a1, a2, a3, a4, a5, a6);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6, typename A7>
		static v8::Handle<v8::Value> Func8(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3, A4, A5, A6, A7);
			ASSERT_PARAM_COUNT_THROW(args, 8);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			(obj->*method)(a0, a1, a2, a3, a4, a5, a6, a7);
			return v8::Undefined();
		}
		template<typename A0, typename A1, typename A2, typename A3, typename A4,
				typename A5, typename A6, typename A7, typename A8>
		static v8::Handle<v8::Value> Func9(const v8::Arguments& args) {
			typedef void (C::*M)(A0, A1, A2, A3, A4, A5, A6, A7, A8);
			ASSERT_PARAM_COUNT_THROW(args, 9);
			M* methodPtr;
			ExtractExternal((void**) &methodPtr, args.Data());
			M method = *methodPtr;
			C* obj = Type<C>::Cast(args.Holder());
			A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			A8 a8 = Type<A8>::Cast(args[8]);
			(obj->*method)(a0, a1, a2, a3, a4, a5, a6, a7, a8);
			return v8::Undefined();
		}
	};

	template<typename C, typename R>
	v8::InvocationCallback GetMethodCallback(R(C::*method)()) {
		return &Method<C, R>::Func0;
	}

	template<typename C, typename R, typename A0>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0)) {
		return &Method<C, R>::template Func1<A0>;
	}

	template<typename C, typename R, typename A0, typename A1>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0, A1)) {
		return &Method<C, R>::template Func2<A0, A1>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0, A1, A2)) {
		return &Method<C, R>::template Func3<A0, A1, A2>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0, A1, A2, A3)) {
		return &Method<C, R>::template Func4<A0, A1, A2, A3>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3, typename A4>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0, A1, A2, A3, A4)) {
		return &Method<C, R>::template Func5<A0, A1, A2, A3, A4>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5>
	v8::InvocationCallback GetMethodCallback(R(C::*method)(A0, A1, A2, A3, A4, A5)) {
		return &Method<C, R>::template Func6<A0, A1, A2, A3, A4, A5>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6>
	v8::InvocationCallback GetMethodCallback(
			R(C::*method)(A0, A1, A2, A3, A4, A5, A6)) {
		return &Method<C, R>::template Func7<A0, A1, A2, A3, A4, A5, A6>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7>
	v8::InvocationCallback GetMethodCallback(
			R(C::*method)(A0, A1, A2, A3, A4, A5, A6, A7)) {
		return &Method<C, R>::template Func8<A0, A1, A2, A3, A4, A5, A6, A7>;
	}

	template<typename C, typename R, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7,
			typename A8>
	v8::InvocationCallback GetMethodCallback(
			R(C::*method)(A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
		return &Method<C, R>::template Func9<A0, A1, A2, A3, A4, A5, A6, A7, A8>;
	}
}

#endif /* METHOD_H_ */
