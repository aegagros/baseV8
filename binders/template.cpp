// $args_count parameters
template<typename R$comma$args_decl>
v8::Handle<v8::Signature> GetFunctionSignature(R (*function) ($args_sign)) {
    v8::Handle<v8::FunctionTemplate> argv[$args_count] = 
    { $args_cast };
    return v8::Signature::New(v8::Handle<v8::FunctionTemplate>(), $args_count, argv);
}

template<typename R, typename C$comma$args_decl>
v8::Handle<v8::Signature> GetMethodSignature(R (C::*function) ($args_sign)) {
    v8::Handle<v8::FunctionTemplate> argv[$args_count] = 
    { $args_cast };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), $args_count, argv);
}

template<typename R, typename C$comma$args_decl>
v8::Handle<v8::Signature> GetGlobalMethodSignature(R (*function) (C*$comma$args_sign)) {
    v8::Handle<v8::FunctionTemplate> argv[$args_count] = 
    { $args_cast };
    return v8::Signature::New(Type<C>::GetFunctionTmpl(), $args_count, argv);
}

