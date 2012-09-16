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
#ifndef TABLE_H_
#define TABLE_H_

#include "Common.h"
#include "Type.h"
#include "Def.h"
#include "Function.h"
#include "Property.h"


namespace base {
	class TableDef : public Def {
	public:
		template<typename F>
		TableDef& func(const char* name, F* func) {
			int flags = v8::DontDelete | v8::ReadOnly;
			void* funcPtr = allocMember(sizeof(F));
			memcpy(funcPtr, &func, sizeof(F));
			getTemplate()->Set(
				v8::String::New(name),
				v8::FunctionTemplate::New(GetFunctionCallback(func), v8::External::New(funcPtr), GetFunctionSignature(func)),
				(v8::PropertyAttribute) flags);
			return *this;
			return *this;
		}

		template<typename V>
		TableDef& var(const char* name, V* var) {
			bindProperty(getTemplate(), name, var);
			return *this;
		}

		TableDef& enumr(const char* name, int value) {
			getTemplate()->Set(name, v8::Integer::New(value));
			return *this;
		}

		void bindTo(Def def = Def()) {
			v8::Handle<v8::ObjectTemplate> table = def.getTemplate();
			v8::Handle<v8::Object> object = getTemplate()->NewInstance();
			if (table.IsEmpty()) {
				if (!v8::Context::InContext())
					v8::ThrowException(FormatString("must be in a context to define object instance '%s'", getName()));
				v8::Context::GetCurrent()->Global()->Set(v8::String::New(getName()), object);
			}
			else
				table->Set(v8::String::New(getName()), object);
		}

		TableDef(const char* name) {
			m_objTempl = v8::ObjectTemplate::New();
			m_name = name;
		}

		operator v8::Handle<v8::ObjectTemplate>() {
			return getTemplate();
		}

	protected:
		v8::Handle<v8::ObjectTemplate> getTemplate() {
			return m_objTempl;
		}

		const char* getName() {
			return m_name.c_str();
		}
	private:
		v8::Handle<v8::ObjectTemplate> m_objTempl;
		std::string m_name;
	};
};


#endif /* TABLE_H_ */
