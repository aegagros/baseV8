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

#ifndef DEF_H_
#define DEF_H_
#include "Common.h"

#define MAX_POOL_SIZE 4096

namespace base {
	class Def {
	private:
		static byte_t m_pool[MAX_POOL_SIZE];
		static byte_t* m_ptr;

	public:
		Def() {}
		virtual ~Def() {}
		virtual void bindTo(Def def = Def()) {}

		static void* allocMember(size_t size) {
			byte_t* tmp_ptr = m_ptr;
			for (size_t i=0; i < size; i++)
				m_ptr++;
			return tmp_ptr;
		};

		virtual v8::Handle<v8::ObjectTemplate> getTemplate() {
			return v8::Handle<v8::ObjectTemplate>();
		};
	};

	byte_t Def::m_pool[MAX_POOL_SIZE];
	byte_t* Def::m_ptr = Def::m_pool;
}

#endif /* DEF_H_ */
