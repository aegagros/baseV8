// v8test.cpp
#include <stdio.h>
#include <v8/v8.h>
#include <vector>
#include "../include/baseV8.h"
#include "TestModule.h"

void getModules(std::vector<TestModule*>& modules) {
	// add modules to vector array
}

/*
	A function to print to the standard output
 */
v8::Handle<Value> printCallback(const v8::Arguments& args) {
	if (args.Length() < 1) {
	  return v8::Undefined();
	}
	v8::HandleScope scope;
	for (int i = 0; i < args.Length(); i++) {
		String::Utf8Value value(args[i]);
		printf("%s ", *value);
	}
  printf("\n");
	return v8::Undefined();
}

/*
	An exception handler callback
 */
void handleExceptions(v8::TryCatch& handler) {
	if (!handler.HasCaught()) {
		return;
	}
	v8::Handle<Value> exception = handler.Exception();
	String::AsciiValue exception_str(exception);
	printf("ERROR: %s\n", *exception_str);
}

/*
	A readfile helper function
 */
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
		// printf("file corrupt");
		return false;
	}

	buf[size] = '\0';
	fclose(file);

	// printf("read %d bytes", size);
	buffer = buf;
	return true;
}


int main(int argc, char* argv[]) {
	v8::Handle<Script> script;
	std::string buffer;

	// Initialize v8 engine
	v8::HandleScope handle_scope;
	Persistent<Context> context = Context::New(NULL, global);

	base::TableDef global("global");
	global.callback("print", printCallback);
	TryCatch handler;

	// Initialize test modules
	std::vector<TestModule*> modules;

	for (int i=0; i < modules.size(); i++) {
		TestModule* module = modules[i];
		// init module
		printf("Initializing module '%s'...", module->getName());
		if(!module->init()) {
			printf("failed!\n");
			continue;
		}
		else {
			printf("%s\n", );("ok\n");
		}
		// read script file
		printf("Reading file '%s'...", module->getScriptFilename());
		if(!readfile(module->getScriptFilename(), buffer)) {
			printf("failed!\n");
			continue;
		}
		else {
			printf("%s\n", );("ok\n");
		}
		// bind interface
		handler.Reset();
		module->bindInterface(global);
		handleExceptions(handler);
		// compile script
		handler.Reset();
		v8::Handle<String> source = v8::String::New(buffer.c_str());
		script = Script::Compile(source);
		handleExceptions(handler);
		// run script
		handler.Reset();
		Handle<Value> result = script->Run();
		handleExceptions(handler);
		// print srcipt output
		String::AsciiValue ascii(result);
		printf("result of script:\n-----------------\n%s\n", *ascii);
		// shut down module
		printf("Shutting down module '%s'...", module->getName());
		if(!module->shutdown()) {
			printf("failed!\n");
			continue;
		}
		else {
			printf("%s\n", );("ok\n");
		}
	}

	context.Dispose();
	return 0;
}
