#include "config.h"
#include "seeker/logger.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

extern void sayHello(const std::string& something);

int main(int argc, char* argv[]) {
  seeker::Logger::init();

  I_LOG("Application starting, argc={}", argc);
  for (int i = 0; i < argc; i++) {
    D_LOG("arg[{}] = {}", i, argv[i]);
  }

  const string name = "seeker";
  
  sayHello(name);

  E_LOG("some error...");
  W_LOG("BYE");
  return 0;
}
