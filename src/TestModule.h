#include "../include/baseV8.h"

class TestModule {
public:
  virtual bool init() = 0;
  virtual bool shutdown() = 0;
  virtual void bindInterface(base::Def& parent) = 0;
  virtual const char* getScriptFilename() = 0;
  virtual const char* getName() = 0;
};
