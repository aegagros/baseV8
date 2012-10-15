// 0 parameters
template<typename R>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) ()) {
    v8::Handle<v8::FunctionTemplate> argv[0] = 
    {  };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 0, argv);
}

template<typename R, typename C>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) ()) {
    v8::Handle<v8::FunctionTemplate> argv[0] = 
    {  };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 0, argv);
}

template<typename R, typename C>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*)) {
    v8::Handle<v8::FunctionTemplate> argv[0] = 
    {  };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 0, argv);
}


// 1 parameters
template<typename R, typename A0>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0)) {
    v8::Handle<v8::FunctionTemplate> argv[1] = 
    { Type<A0>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 1, argv);
}

template<typename R, typename C, typename A0>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0)) {
    v8::Handle<v8::FunctionTemplate> argv[1] = 
    { Type<A0>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 1, argv);
}

template<typename R, typename C, typename A0>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0)) {
    v8::Handle<v8::FunctionTemplate> argv[1] = 
    { Type<A0>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 1, argv);
}


// 2 parameters
template<typename R, typename A0, typename A1>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1)) {
    v8::Handle<v8::FunctionTemplate> argv[2] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 2, argv);
}

template<typename R, typename C, typename A0, typename A1>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1)) {
    v8::Handle<v8::FunctionTemplate> argv[2] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 2, argv);
}

template<typename R, typename C, typename A0, typename A1>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1)) {
    v8::Handle<v8::FunctionTemplate> argv[2] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 2, argv);
}


// 3 parameters
template<typename R, typename A0, typename A1, typename A2>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2)) {
    v8::Handle<v8::FunctionTemplate> argv[3] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 3, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2)) {
    v8::Handle<v8::FunctionTemplate> argv[3] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 3, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2)) {
    v8::Handle<v8::FunctionTemplate> argv[3] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 3, argv);
}


// 4 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3)) {
    v8::Handle<v8::FunctionTemplate> argv[4] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 4, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3)) {
    v8::Handle<v8::FunctionTemplate> argv[4] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 4, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3)) {
    v8::Handle<v8::FunctionTemplate> argv[4] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 4, argv);
}


// 5 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3, A4)) {
    v8::Handle<v8::FunctionTemplate> argv[5] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 5, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3, A4)) {
    v8::Handle<v8::FunctionTemplate> argv[5] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 5, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3, A4)) {
    v8::Handle<v8::FunctionTemplate> argv[5] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 5, argv);
}


// 6 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3, A4, A5)) {
    v8::Handle<v8::FunctionTemplate> argv[6] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 6, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3, A4, A5)) {
    v8::Handle<v8::FunctionTemplate> argv[6] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 6, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3, A4, A5)) {
    v8::Handle<v8::FunctionTemplate> argv[6] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 6, argv);
}


// 7 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3, A4, A5, A6)) {
    v8::Handle<v8::FunctionTemplate> argv[7] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 7, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3, A4, A5, A6)) {
    v8::Handle<v8::FunctionTemplate> argv[7] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 7, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3, A4, A5, A6)) {
    v8::Handle<v8::FunctionTemplate> argv[7] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 7, argv);
}


// 8 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3, A4, A5, A6, A7)) {
    v8::Handle<v8::FunctionTemplate> argv[8] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 8, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3, A4, A5, A6, A7)) {
    v8::Handle<v8::FunctionTemplate> argv[8] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 8, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3, A4, A5, A6, A7)) {
    v8::Handle<v8::FunctionTemplate> argv[8] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 8, argv);
}


// 9 parameters
template<typename R, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) (A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
    v8::Handle<v8::FunctionTemplate> argv[9] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl(), Type<A8>::GetFunctionTmpl() };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), 9, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) (A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
    v8::Handle<v8::FunctionTemplate> argv[9] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl(), Type<A8>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 9, argv);
}

template<typename R, typename C, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*, A0, A1, A2, A3, A4, A5, A6, A7, A8)) {
    v8::Handle<v8::FunctionTemplate> argv[9] = 
    { Type<A0>::GetFunctionTmpl(), Type<A1>::GetFunctionTmpl(), Type<A2>::GetFunctionTmpl(), Type<A3>::GetFunctionTmpl(), Type<A4>::GetFunctionTmpl(), Type<A5>::GetFunctionTmpl(), Type<A6>::GetFunctionTmpl(), Type<A7>::GetFunctionTmpl(), Type<A8>::GetFunctionTmpl() };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), 9, argv);
}


