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

#ifndef BASEV8_MAX_POOL_SIZE
#define BASEV8_MAX_POOL_SIZE 16384
#endif

namespace base {
  /**
   * @brief Abstract base class for definitions.
   *
   * This class holds a static pointer to an elementary-implemented memory pool
   * where all the allocated function and member function pointers are stored.
   * By default the memory allocated for the pool is 16384 bytes (16K), but it
   * can be changed by defining the BASEV8_MAX_POOL_SIZE macro before including
   * the baseV8.h header file. The memory pool will be freed upon program end.
   */
  class Def {
  private:
    static byte_t m_pool[BASEV8_MAX_POOL_SIZE];
    static byte_t* m_ptr;

  public:
    Def() {}
    virtual ~Def() {}

    /**
     * @brief Bind this definition to another definition's member list.
     * @param def The parent definition to bind to.
     */
    virtual void bindTo(Def def = Def()) {}

    /**
     * @brief Allocate memory from the memory pool (usually for internal use).
     * @param size The size of memory to allocate in bytes.
     */
    static void* allocMember(size_t size) {
      byte_t* tmp_ptr = m_ptr;
      for (size_t i=0; i < size; i++) {
        m_ptr++;
      }
      return tmp_ptr;
    };

    /**
     * @brief Get the object template for this definition.
     * @return The handle to the v8::ObjectTemplate for use with the V8 API.
     */
    virtual v8::Handle<v8::ObjectTemplate> getTemplate() {
      return v8::Handle<v8::ObjectTemplate>();
    };

    /**
     * @brief Automatically convert base::Def instances to v8::ObjectTemplate
     * instances.
     *
     * This is very useful for creating v8::Context instances using global
     * objects defined using the baseV8 API.
     * @return Same as base::Def::getTemplate()
     */
    operator v8::Handle<v8::ObjectTemplate>() { return getTemplate(); }
  };

  byte_t Def::m_pool[BASEV8_MAX_POOL_SIZE];
  byte_t* Def::m_ptr = Def::m_pool;
}

#endif /* DEF_H_ */
