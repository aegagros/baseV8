//============================================================================
// Name        : v8test.cpp
// Author      :
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <v8/v8.h>
#include <vector>
#include "../include/baseV8.h"
#include "test_decls.h.h"

using namespace v8;

Handle<Value> printCallback(const Arguments& args) {
	if (args.Length() < 1) {
	  return v8::Undefined();
	}
	HandleScope scope;
	for (int i = 0; i < args.Length(); i++) {
		String::Utf8Value value(args[i]);
		printf("%s ", *value);
	}
  printf("\n");
	return v8::Undefined();
}

void handleExceptions(v8::TryCatch& handler) {
	if (!handler.HasCaught()) {
		return;
	}
	Handle<Value> exception = handler.Exception();
	String::AsciiValue exception_str(exception);
	printf("ERROR: %s\n", *exception_str);
}

bool readfile(const char* filename, std::string& buffer) {
	buffer = "";
	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("file not found or not accesible");
		return false;
	}

	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);

	fseek(file, 0, SEEK_SET);
	char buf[size+1];
	size_t res = fread(buf, 1, size, file);

	if (res < size) {
		printf("file corrupt");
		return false;
	}

	buf[size] = '\0';
	fclose(file);

	printf("read %d bytes", size);
	buffer = buf;
	return true;
}


int main(int argc, char* argv[]) {
	Handle<Script> script;
	std::string buffer;

	HandleScope handle_scope;
	Handle<ObjectTemplate> global = ObjectTemplate::New();
	/**
	 * TODO: It's better to use the framework to bind the 'print' function. Find a
	 * way to use a baseV8::ClassDef<> or a baseV8::TableDef to construct a global
	 * object for use with a context.
	 */
	global->Set(String::New("print"), FunctionTemplate::New(printCallback));
	Persistent<Context> context = Context::New(NULL, global);

	Context::Scope context_scope(context);
	TryCatch handler;

  // TODO: no need
	for (int i=1; i < argc; i++) {
		printf("File '%s': reading...", argv[i]);
		if(!readfile(argv[i], buffer))
			continue;
		Handle<String> source = String::New(buffer.c_str());

		printf("...compiling...");
		handler.Reset();
		script = Script::Compile(source);
		handleExceptions(handler);

		printf("...executing:\n");
		handler.Reset();
		Handle<Value> result = script->Run();
		handleExceptions(handler);
		String::AsciiValue ascii(result);
		printf("result of script: %s\n", *ascii);
	}

	context.Dispose();
	return 0;
}
