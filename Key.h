//
// Created by actua on 5/21/2024.
//

#ifndef KEY_H
#define KEY_H

#include <string>
#include <fstream>

class Key {
public:
  // Constructor
  explicit Key(const std::string& fname);
  ~Key();

  void logKey(char key);
  static std::string translateKey(int key);

private:
  std::ofstream keyLog;
};


#endif //KEY_H
