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

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "Type.h"
#include "Common.h"

namespace base {

	template <typename R>
	struct Function {
		// 0 parameters
		static v8::Handle<v8::Value> Func0(const v8::Arguments& args) {
		    typedef R (*F) ();
		    ASSERT_PARAM_COUNT_THROW(args, 0);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;

		    R ret_val = func();
		    return Type<R>::Cast(ret_val);
		}

		// 1 parameters
		template<typename A0>
		static v8::Handle<v8::Value> Func1(const v8::Arguments& args) {
		    typedef R (*F) (A0);
		    ASSERT_PARAM_COUNT_THROW(args, 1);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);

		    R ret_val = func(a0);
		    return Type<R>::Cast(ret_val);
		}

		// 2 parameters
		template<typename A0, typename A1>
		static v8::Handle<v8::Value> Func2(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1);
		    ASSERT_PARAM_COUNT_THROW(args, 2);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);

		    R ret_val = func(a0, a1);
		    return Type<R>::Cast(ret_val);
		}

		// 3 parameters
		template<typename A0, typename A1, typename A2>
		static v8::Handle<v8::Value> Func3(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2);
		    ASSERT_PARAM_COUNT_THROW(args, 3);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);

		    R ret_val = func(a0, a1, a2);
		    return Type<R>::Cast(ret_val);
		}

		// 4 parameters
		template<typename A0, typename A1, typename A2, typename A3>
		static v8::Handle<v8::Value> Func4(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3);
		    ASSERT_PARAM_COUNT_THROW(args, 4);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);

		    R ret_val = func(a0, a1, a2, a3);
		    return Type<R>::Cast(ret_val);
		}

		// 5 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4>
		static v8::Handle<v8::Value> Func5(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3, A4);
		    ASSERT_PARAM_COUNT_THROW(args, 5);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);

		    R ret_val = func(a0, a1, a2, a3, a4);
		    return Type<R>::Cast(ret_val);
		}

		// 6 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
		static v8::Handle<v8::Value> Func6(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3, A4, A5);
		    ASSERT_PARAM_COUNT_THROW(args, 6);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);

		    R ret_val = func(a0, a1, a2, a3, a4, a5);
		    return Type<R>::Cast(ret_val);
		}

		// 7 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
		static v8::Handle<v8::Value> Func7(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3, A4, A5, A6);
		    ASSERT_PARAM_COUNT_THROW(args, 7);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);

		    R ret_val = func(a0, a1, a2, a3, a4, a5, a6);
		    return Type<R>::Cast(ret_val);
		}

		// 8 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
		static v8::Handle<v8::Value> Func8(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3, A4, A5, A6, A7);
		    ASSERT_PARAM_COUNT_THROW(args, 8);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);

		    R ret_val = func(a0, a1, a2, a3, a4, a5, a6, a7);
		    return Type<R>::Cast(ret_val);
		}

		// 9 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
		static v8::Handle<v8::Value> Func9(const v8::Arguments& args) {
		    typedef R (*F) (A0, A1, A2, A3, A4, A5, A6, A7, A8);
		    ASSERT_PARAM_COUNT_THROW(args, 9);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			A8 a8 = Type<A8>::Cast(args[8]);

		    R ret_val = func(a0, a1, a2, a3, a4, a5, a6, a7, a8);
		    return Type<R>::Cast(ret_val);
		}
	};

	template <>
	struct Function<void> {
		//0 parameters
		static v8::Handle<v8::Value> Func0(const v8::Arguments& args) {
		    typedef void (*F) ();
		    ASSERT_PARAM_COUNT_THROW(args, 0);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;

		    func();
		    return v8::Undefined();
		}

		// 1 parameters
		template<typename A0>
		static v8::Handle<v8::Value> Func1(const v8::Arguments& args) {
		    typedef void (*F) (A0);
		    ASSERT_PARAM_COUNT_THROW(args, 1);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);

		    func(a0);
		    return v8::Undefined();
		}

		// 2 parameters
		template<typename A0, typename A1>
		static v8::Handle<v8::Value> Func2(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1);
		    ASSERT_PARAM_COUNT_THROW(args, 2);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);

		    func(a0, a1);
		    return v8::Undefined();
		}

		// 3 parameters
		template<typename A0, typename A1, typename A2>
		static v8::Handle<v8::Value> Func3(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2);
		    ASSERT_PARAM_COUNT_THROW(args, 3);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);

		    func(a0, a1, a2);
		    return v8::Undefined();
		}

		// 4 parameters
		template<typename A0, typename A1, typename A2, typename A3>
		static v8::Handle<v8::Value> Func4(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3);
		    ASSERT_PARAM_COUNT_THROW(args, 4);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);

		    func(a0, a1, a2, a3);
		    return v8::Undefined();
		}

		// 5 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4>
		static v8::Handle<v8::Value> Func5(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3, A4);
		    ASSERT_PARAM_COUNT_THROW(args, 5);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);

		    func(a0, a1, a2, a3, a4);
		    return v8::Undefined();
		}

		// 6 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
		static v8::Handle<v8::Value> Func6(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3, A4, A5);
		    ASSERT_PARAM_COUNT_THROW(args, 6);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);

		    func(a0, a1, a2, a3, a4, a5);
		    return v8::Undefined();
		}

		// 7 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
		static v8::Handle<v8::Value> Func7(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3, A4, A5, A6);
		    ASSERT_PARAM_COUNT_THROW(args, 7);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);

		    func(a0, a1, a2, a3, a4, a5, a6);
		    return v8::Undefined();
		}

		// 8 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
		static v8::Handle<v8::Value> Func8(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3, A4, A5, A6, A7);
		    ASSERT_PARAM_COUNT_THROW(args, 8);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);

		    func(a0, a1, a2, a3, a4, a5, a6, a7);
		    return v8::Undefined();
		}

		// 9 parameters
		template<typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
		static v8::Handle<v8::Value> Func9(const v8::Arguments& args) {
		    typedef void (*F) (A0, A1, A2, A3, A4, A5, A6, A7, A8);
		    ASSERT_PARAM_COUNT_THROW(args, 9);
		    F* funcPtr;
		    ExtractExternal((void**) &funcPtr, args.Data());
		    F func = *funcPtr;
		    A0 a0 = Type<A0>::Cast(args[0]);
			A1 a1 = Type<A1>::Cast(args[1]);
			A2 a2 = Type<A2>::Cast(args[2]);
			A3 a3 = Type<A3>::Cast(args[3]);
			A4 a4 = Type<A4>::Cast(args[4]);
			A5 a5 = Type<A5>::Cast(args[5]);
			A6 a6 = Type<A6>::Cast(args[6]);
			A7 a7 = Type<A7>::Cast(args[7]);
			A8 a8 = Type<A8>::Cast(args[8]);

		    func(a0, a1, a2, a3, a4, a5, a6, a7, a8);
		    return v8::Undefined();
		}
	};

	template<typename R>
	v8::InvocationCallback GetFunctionCallback(R (*function) ()) {
	    return &Function<R>::template Func0<>;
	}

	// 1 parameters
	template<typename R, typename A0>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0)) {
	    return &Function<R>::template Func1<A0>;
	}

	// 2 parameters
	template<typename R, typename A0, typename A1>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1)) {
	    return &Function<R>::template Func2<A0, A1>;
	}

	// 3 parameters
	template<typename R, typename A0, typename A1, typename A2>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2)) {
	    return &Function<R>::template Func3<A0, A1, A2>;
	}

	// 4 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3)) {
	    return &Function<R>::template Func4<A0, A1, A2, A3>;
	}

	// 5 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3, A4)) {
	    return &Function<R>::template Func5<A0, A1, A2, A3, A4>;
	}

	// 6 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3, A4, A5)) {
	    return &Function<R>::template Func6<A0, A1, A2, A3, A4, A5>;
	}

	// 7 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3, A4, A5, A6)) {
	    return &Function<R>::template Func7<A0, A1, A2, A3, A4, A5, A6>;
	}

	// 8 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3, A4, A5, A6, A7)) {
	    return &Function<R>::template Func8<A0, A1, A2, A3, A4, A5, A6, A7>;
	}

	// 9 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	v8::InvocationCallback GetFunctionCallback(R (*function) (A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
	    return &Function<R>::template Func9<A0, A1, A2, A3, A4, A5, A6, A7, A8>;
	}
}

#endif /* FUNCTION_H_ */
