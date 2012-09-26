baseV8 - Template-based C++ to v8 javascript binding utilities

Usage Instructions
==================
This is a header-only library. Just place the headers located in the 'include'
folder in your project and include 'baseV8.h' file. For further documentation
refer to the inline documentation, or the doxygen extracted documentation.

Building
========
To build the testing sample in linux/gcc, just navigate to the build folder and
run 'make'. The binary will be placed in the 'bin' folder. To build the doxygen
documentation run 'doxygen' the build folder. The doc html files will be placed
in the 'doc/html' folder.

Influence / Inspiration
=======================
This library is largely inspired by Stephan Beal's code for [v8-juice]
(http://code.google.com/p/v8-juice/). His work acted as a source of reference
and influence. However, having worked with libraries for the squirrel scripting
language, I prefered the simplicity of the interface and the binding code of
[sqrat](http://scrat.sourceforge.net/) and [sqbind]
(http://code.google.com/p/sqbind/).

Disclaimer
==========
This is my first attempt in distributing my code. It is a far from complete work
in progress. Please do not rely on the efficiency, safety or stability of this
software. If you need to use a production-level v8 binding library, please use
v8-juice.

To-do:
======
Things to implement:

* Object instances binding as tables

Things to test:

* Inheritance.
* Custom class-types converting.
* Passing v8 types (handles) as parameters.


Licence
=======
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
