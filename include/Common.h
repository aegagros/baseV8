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

#include "../../v8/include/v8.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string>

/**
 * @file
 * @brief Common declarations and functions
 *
 * This file contains the include statements to v8 headers and commonly used
 * standard libraries. Some utility global functions are declared here mostly
 * for internal use.
 */

/*
  Define a macro for checking function arity. This is to be called inside
  template function binders.
 */
#define ASSERT_PARAM_COUNT_THROW(argsv, count)  if(argsv.Length() != count) { \
                          v8::String::AsciiValue s(                           \
                              args.Callee()->GetName()->ToString()            \
                          );                                                  \
                          return v8::ThrowException(FormatString(             \
                            "%s(): function arity mismatch, expecting %d arguments, received %d",\
                            *s, count, argsv.Length())); }                    \
/*
#define ASSERT_PARAM_COUNT_THROW
 */

/**
 * @brief The primary namespace for all classes and functions
 */
namespace base {
  /**
   * @brief Helper function to extract arbitrary native data wrapped inside a
   * v8::External object instance.
   *
   * @param data    Pointer to a void* pointer to store the data.
   * @param extData The handle to the v8::External instance.
   */
  void ExtractExternal(void** data, v8::Handle<v8::External> extData) {
    *data = v8::External::Unwrap(extData);
  }

  /**
   * @brief Helper function to extract arbitrary native data wrapped inside a
   * v8::Value object instance.
   *
   * @param data  Pointer to a void* pointer to store the data.
   * @param value The handle to the v8::External instance.
   */
  void ExtractExternal(void** data, v8::Handle<v8::Value> value) {
    v8::Handle<v8::External> extData = v8::Handle<v8::External>::Cast(value);
    if(!extData.IsEmpty()) {
      *data = v8::External::Unwrap(extData);
    }
    else {
      *data = 0;
    }
  }

  /**
   * @brief Helper function to construct a formatted v8::String object.
   *
   * @param fmt Format string according to stdlib printf() function.
   */
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
