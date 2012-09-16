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
#ifndef BASEV8_H_
#define BASEV8_H_

/**
 * @mainpage Introduction
 *
 *
 * The baseV8 library facilitates the binding of native C++ classes to the Google v8 javascript engine. Using simple
 * calls, it provides a way to automatically generate intermediate binding code to handle the calls to the native methods,
 * static functions, constructors etc. It relies on template metaprogramming and template specialization.
 *
 * baseV8 can expose classes as function constructors and single object instances as individual object
 * namespaces (tables). These are handled by two main classes:
 *
 * <ul>
 *   <li>base::ClassDef template class, and</li>
 *   <li>base::TableDef class.</li>
 * </ul>
 *
 * @section example Example usage
 *
 * Consider the following C++ class declaration:
 * @code
 * class MyClass {
 * public:
 *   MyClass();
 *   MyClass(int i);
 *
 *   int aMethod();
 *   void anotherMethod(std::string s);
 *
 *   void setReal(float f);
 *   float getReal() const;
 *
 * private:
 *   float m_real;
 *
 * }
 * @endcode
 *
 * To bind the class to javascript you can use the following code:
 * @code
 * base::ClassDef<MyClass>("MyClass")
 *   .constructor()
 *   .constructor<MyClass* (int)>()
 *   .method("aMethod", &MyClass::aMethod)
 *   .method("anotherMethod", &MyClass::anotherMethod)
 *   .prop("real", &MyClass::getReal, &MyClass::setReal)
 *   .bind();
 * @endcode
 *
 * Afterwards, you can use the class inside javascript:
 * @code
 * var obj = new MyClass();
 * print (obj.aMethod());
 * print (obj.real);
 * obj.anotherMethod('a string');
 * @endcode
 *
 * @section inspiration Inspiration
 *
 * This library is inspired by and largely based on
 *  <a href="http://code.google.com/p/v8-juice/wiki/V8Convert">v8-juice</a>,
 * as well as other template-based binding libraries like
 * <a href="http://www.boost.org/doc/libs/1_49_0/libs/python/doc/">boost::python</a>,
 * <a href="http://code.google.com/p/sqbind/">sqbind</a> and
 * <a href="http://scrat.sourceforge.net/">sqrat</a>.
 *
 */

#include "Table.h"
#include "Class.h"
#include "Table.h"

#endif /* BASEV8_H_ */
