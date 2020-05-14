
#include <string>
#include <seeker/loggerApi.h>

void sayHello(const std::string& something) {

  I_LOG("say: {}", something);

}