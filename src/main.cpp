#include "config.h"
#include "seeker/logger.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;

extern void sayHello(const std::string& something);

std::string longMsg(const std::string& msg, int c) {
  std::string rst{msg};
  for (int i = 0; i < c; i++) {
    rst += msg;
  }
  return rst;
}


int main(int argc, char* argv[]) {
  std::cout << "=============   1    =================" << std::endl;
  seeker::Logger::init();

  I_LOG("Application starting, argc={}", argc);
  for (int i = 0; i < argc; i++) {
    D_LOG("arg[{}] = {}", i, argv[i]);
  }


  const string name = "seeker";

  sayHello(name);
  std::cout << "=============   2    =================" << std::endl;

  E_LOG("some error...");
  std::cout << "=============   3    =================" << std::endl;
  I_LOG("longMsg msg: {}", longMsg("I am here!,", 30));
  std::cout << "=============   4    =================" << std::endl;
  W_LOG("BYE");
  return 0;
}
