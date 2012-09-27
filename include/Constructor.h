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
/**
 * @file
 * @brief Template structures for constructors based on arity
 *
 * The createConstructor() function takes a pointer to a dummy function as
 * parameter, from which only the signature is used to select from the available
 * overloads. Since the dummy function is never called, it can be a null
 * pointer.
 */
#ifndef CONSTRUCTOR_H_
#define CONSTRUCTOR_H_

#include "Common.h"
#include "Class.h"
#include "Type.h"

#define ASSERT_PARAM_COUNT(argsv, count) if(argsv.Length() != count) { return 0 }
#define ASSERT_PARAM_TYPE(argsv, type, index) \
  if (!ClassDef<type>::Assert(argsv[(index)])) { return 0 }

namespace base {
  template <typename C>
  struct Constr0 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 0);
      return new C();
    };
  };
  template <typename C, typename A0>
  struct Constr1 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 1);
      ASSERT_PARAM_TYPE(args, A0, 0);
      return new C(Type<A0>::Cast(args[0]));
    };
  };
  template <typename C, typename A0, typename A1>
  struct Constr2 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 2);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2>
  struct Constr3 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 3);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3>
  struct Constr4 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 4);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4>
  struct Constr5 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 5);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      ASSERT_PARAM_TYPE(args, A4, 4);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]),
             Type<A4>::Cast(args[4]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5>
  struct Constr6 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 6);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      ASSERT_PARAM_TYPE(args, A4, 4);
      ASSERT_PARAM_TYPE(args, A5, 5);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]),
             Type<A4>::Cast(args[4]),
             Type<A5>::Cast(args[5]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6>
  struct Constr7 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 7);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      ASSERT_PARAM_TYPE(args, A4, 4);
      ASSERT_PARAM_TYPE(args, A5, 5);
      ASSERT_PARAM_TYPE(args, A6, 6);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]),
             Type<A4>::Cast(args[4]),
             Type<A5>::Cast(args[5]),
             Type<A6>::Cast(args[6]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6, typename A7>
  struct Constr8 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 8);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      ASSERT_PARAM_TYPE(args, A4, 4);
      ASSERT_PARAM_TYPE(args, A5, 5);
      ASSERT_PARAM_TYPE(args, A6, 6);
      ASSERT_PARAM_TYPE(args, A7, 7);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]),
             Type<A4>::Cast(args[4]),
             Type<A5>::Cast(args[5]),
             Type<A6>::Cast(args[6]),
             Type<A7>::Cast(args[7]));
    };
  };
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6, typename A7, typename A8>
  struct Constr9 {
    static C* Create(const v8::Arguments& args) {
      ASSERT_PARAM_COUNT(args, 9);
      ASSERT_PARAM_TYPE(args, A0, 0);
      ASSERT_PARAM_TYPE(args, A1, 1);
      ASSERT_PARAM_TYPE(args, A2, 2);
      ASSERT_PARAM_TYPE(args, A3, 3);
      ASSERT_PARAM_TYPE(args, A4, 4);
      ASSERT_PARAM_TYPE(args, A5, 5);
      ASSERT_PARAM_TYPE(args, A6, 6);
      ASSERT_PARAM_TYPE(args, A7, 7);
      ASSERT_PARAM_TYPE(args, A8, 8);
      return new C(Type<A0>::Cast(args[0]),
             Type<A1>::Cast(args[1]),
             Type<A2>::Cast(args[2]),
             Type<A3>::Cast(args[3]),
             Type<A4>::Cast(args[4]),
             Type<A5>::Cast(args[5]),
             Type<A6>::Cast(args[6]),
             Type<A7>::Cast(args[7]),
             Type<A8>::Cast(args[8]));
    };
  };
  template <typename C>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (void)) {
      return Constr0<C>::Create;
    }
  template <typename C, typename A0>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0)) {
      return Constr1<C, A0>::Create;
    }
  template <typename C, typename A0, typename A1>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1)) {
      return Constr2<C, A0, A1>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2)) {
      return Constr3<C, A0, A1, A2>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3)) {
      return Constr4<C, A0, A1, A2, A3>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3, A4)) {
      return Constr5<C, A0, A1, A2, A3, A4>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3, A4, A5)) {
      return Constr6<C, A0, A1, A2, A3, A4, A5>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3, A4, A5, A6)) {
      return Constr7<C, A0, A1, A2, A3, A4, A5, A6>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6, typename A7>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3, A4, A5, A6, A7)) {
      return Constr8<C, A0, A1, A2, A3, A4, A5, A6, A7>::Create;
    }
  template <typename C, typename A0, typename A1, typename A2, typename A3,
            typename A4, typename A5, typename A6, typename A7, typename A8>
  typename ClassDef<C>::ConstructorCallback
    createConstructor(C* (*dummy_func) (A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
      return Constr9<C, A0, A1, A2, A3, A4, A5, A6, A7, A8>::Create;
    }
};

#endif /* CONSTRUCTOR_H_ */
