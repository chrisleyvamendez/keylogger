//
// Created by actua on 5/21/2024.
//

#ifndef KEYLOG_H
#define KEYLOG_H

#include <atomic>


#include "FileHandler.h"
#include "Key.h"
#include <string>
#include <thread>


class KeyLog {
public:
  explicit KeyLog(const std::string &fname);
  void start();
  void stop();
  void logLoop();

private:
  Key keyHandler;
  std::atomic<bool> running;
  FileHandler fileHandler;
  std::thread logthread;
};


#endif //KEYLOG_H
