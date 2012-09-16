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

#ifndef SIGNATURES_H_
#define SIGNATURES_H_

#include "Common.h"
#include "Type.h"
#include "Class.h"

namespace base {
	// 0 parameters
	template<typename R>
	v8::Handle<v8::Signature> GetFunctionSignature(R(*function)()) {
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>());
	}

	template<typename R, typename C>
	v8::Handle<v8::Signature> GetMethodSignature(R(C::*function)()) {
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl());
	}

	template<typename R, typename C>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(R(*function)(C*)) {
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl());
	}

	// 1 parameters
	template<typename R, typename A0>
	v8::Handle<v8::Signature> GetFunctionSignature(R(*function)(A0)) {
		v8::Handle<v8::FunctionTemplate> argv[1] = { ClassDef<A0>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 1, argv);
	}

	template<typename R, typename C, typename A0>
	v8::Handle<v8::Signature> GetMethodSignature(R(C::*function)(A0)) {
		v8::Handle<v8::FunctionTemplate> argv[1] = { ClassDef<A0>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 1, argv);
	}

	template<typename R, typename C, typename A0>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(R(*function)(C*, A0)) {
		v8::Handle<v8::FunctionTemplate> argv[1] = { ClassDef<A0>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 1, argv);
	}

	// 2 parameters
	template<typename R, typename A0, typename A1>
	v8::Handle<v8::Signature> GetFunctionSignature(R(*function)(A0, A1)) {
		v8::Handle<v8::FunctionTemplate> argv[2] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 2, argv);
	}

	template<typename R, typename C, typename A0, typename A1>
	v8::Handle<v8::Signature> GetMethodSignature(R(C::*function)(A0, A1)) {
		v8::Handle<v8::FunctionTemplate> argv[2] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 2, argv);
	}

	template<typename R, typename C, typename A0, typename A1>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(R(*function)(C*, A0, A1)) {
		v8::Handle<v8::FunctionTemplate> argv[2] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 2, argv);
	}

	// 3 parameters
	template<typename R, typename A0, typename A1, typename A2>
	v8::Handle<v8::Signature> GetFunctionSignature(R(*function)(A0, A1, A2)) {
		v8::Handle<v8::FunctionTemplate> argv[3] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 3, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2>
	v8::Handle<v8::Signature> GetMethodSignature(R(C::*function)(A0, A1, A2)) {
		v8::Handle<v8::FunctionTemplate> argv[3] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 3, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2)) {
		v8::Handle<v8::FunctionTemplate> argv[3] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 3, argv);
	}

	// 4 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3>
	v8::Handle<v8::Signature> GetFunctionSignature(R(*function)(A0, A1, A2, A3)) {
		v8::Handle<v8::FunctionTemplate> argv[4] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 4, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3>
	v8::Handle<v8::Signature> GetMethodSignature(R(C::*function)(A0, A1, A2, A3)) {
		v8::Handle<v8::FunctionTemplate> argv[4] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 4, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3)) {
		v8::Handle<v8::FunctionTemplate> argv[4] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 4, argv);
	}

	// 5 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3,
			typename A4>
	v8::Handle<v8::Signature> GetFunctionSignature(
			R(*function)(A0, A1, A2, A3, A4)) {
		v8::Handle<v8::FunctionTemplate> argv[5] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 5, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4>
	v8::Handle<v8::Signature> GetMethodSignature(
			R(C::*function)(A0, A1, A2, A3, A4)) {
		v8::Handle<v8::FunctionTemplate> argv[5] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 5, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3, A4)) {
		v8::Handle<v8::FunctionTemplate> argv[5] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 5, argv);
	}

	// 6 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3,
			typename A4, typename A5>
	v8::Handle<v8::Signature> GetFunctionSignature(
			R(*function)(A0, A1, A2, A3, A4, A5)) {
		v8::Handle<v8::FunctionTemplate> argv[6] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 6, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5>
	v8::Handle<v8::Signature> GetMethodSignature(
			R(C::*function)(A0, A1, A2, A3, A4, A5)) {
		v8::Handle<v8::FunctionTemplate> argv[6] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 6, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3, A4, A5)) {
		v8::Handle<v8::FunctionTemplate> argv[6] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 6, argv);
	}

	// 7 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3,
			typename A4, typename A5, typename A6>
	v8::Handle<v8::Signature> GetFunctionSignature(
			R(*function)(A0, A1, A2, A3, A4, A5, A6)) {
		v8::Handle<v8::FunctionTemplate> argv[7] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 7, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6>
	v8::Handle<v8::Signature> GetMethodSignature(
			R(C::*function)(A0, A1, A2, A3, A4, A5, A6)) {
		v8::Handle<v8::FunctionTemplate> argv[7] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 7, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3, A4, A5, A6)) {
		v8::Handle<v8::FunctionTemplate> argv[7] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 7, argv);
	}

	// 8 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3,
			typename A4, typename A5, typename A6, typename A7>
	v8::Handle<v8::Signature> GetFunctionSignature(
			R(*function)(A0, A1, A2, A3, A4, A5, A6, A7)) {
		v8::Handle<v8::FunctionTemplate> argv[8] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 8, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7>
	v8::Handle<v8::Signature> GetMethodSignature(
			R(C::*function)(A0, A1, A2, A3, A4, A5, A6, A7)) {
		v8::Handle<v8::FunctionTemplate> argv[8] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 8, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3, A4, A5, A6, A7)) {
		v8::Handle<v8::FunctionTemplate> argv[8] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 8, argv);
	}

	// 9 parameters
	template<typename R, typename A0, typename A1, typename A2, typename A3,
			typename A4, typename A5, typename A6, typename A7, typename A8>
	v8::Handle<v8::Signature> GetFunctionSignature(
			R(*function)(A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
		v8::Handle<v8::FunctionTemplate> argv[9] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl(), ClassDef<A8>::GetFunctionTmpl() };
		return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 9, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7,
			typename A8>
	v8::Handle<v8::Signature> GetMethodSignature(
			R(C::*function)(A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
		v8::Handle<v8::FunctionTemplate> argv[9] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl(), ClassDef<A8>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 9, argv);
	}

	template<typename R, typename C, typename A0, typename A1, typename A2,
			typename A3, typename A4, typename A5, typename A6, typename A7,
			typename A8>
	v8::Handle<v8::Signature> GetGlobalMethodSignature(
			R(*function)(C*, A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
		v8::Handle<v8::FunctionTemplate> argv[9] = { ClassDef<A0>::GetFunctionTmpl(),
				ClassDef<A1>::GetFunctionTmpl(), ClassDef<A2>::GetFunctionTmpl(),
				ClassDef<A3>::GetFunctionTmpl(), ClassDef<A4>::GetFunctionTmpl(),
				ClassDef<A5>::GetFunctionTmpl(), ClassDef<A6>::GetFunctionTmpl(),
				ClassDef<A7>::GetFunctionTmpl(), ClassDef<A8>::GetFunctionTmpl() };
		return v8::Signature::New(ClassDef<C>::GetFunctionTmpl(), 9, argv);
	}
}

#endif /* SIGNATURES_H_ */
