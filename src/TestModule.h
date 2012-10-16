#include "../include/baseV8.h"
#include <string>

class TestModule {
private:
  std::string m_name;
public:
  TestModule(const char* name) : m_name(name) {};
  virtual ~TestModule() {};

  virtual bool init() = 0;
  virtual bool shutdown() = 0;
  virtual void bindInterface(base::Def& parent) = 0;
  virtual const char* getScriptFilename() = 0;
  virtual const char* getName() { return m_name.c_str(); };
};
