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
#ifndef COMMON_H_
#define COMMON_H_

#include <v8/v8.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>

/*
#define ASSERT_PARAM_COUNT_THROW(argsv, count)	if(argsv.Length() != count) {											\
													v8::String::AsciiValue s(args.Callee()->GetName()->ToString());		\
													return v8::ThrowException(FormatString(								\
														"%s(): function arity mismatch, expecting %d arguments, received %d",\
														*s, count, argsv.Length())); }									\
*/
#define ASSERT_PARAM_COUNT_THROW

/**
 * @brief The primary namespace for all classes and functions
 */
namespace base {
	void ExtractExternal(void** data, v8::Handle<v8::External> extData) {
		*data = v8::External::Unwrap(extData);
	}

	void ExtractExternal(void** data, v8::Handle<v8::Value> value) {
		v8::Handle<v8::External> extData = v8::Handle<v8::External>::Cast(value);
		if(!extData.IsEmpty())
			*data = v8::External::Unwrap(extData);
		else
			*data = 0;
	}

	v8::Handle<v8::String> FormatString(const char* fmt, ...) {
		static char buf[256] = "";
		va_list args;
		va_start(args, fmt);
		vsprintf (buf, fmt, args);
		va_end(args);
		v8::HandleScope handle_scope;
		v8::Handle<v8::String> str = v8::String::New(buf);
		return handle_scope.Close(str);
	}

	typedef unsigned char byte_t;
}

#endif /* COMMON_H_ */
