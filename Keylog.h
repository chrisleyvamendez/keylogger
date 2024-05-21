//
// Created by actua on 5/21/2024.
//

#ifndef KEYLOG_H
#define KEYLOG_H

#include "Key.h"

#include <string>

class KeyLog {
public:
  KeyLog(const std::string &fname);
  void start();

private:
  Key keyHandler;
  void logLoop();
};


#endif //KEYLOG_H
