//
// Created by actua on 5/21/2024.
//

#ifndef KEY_H
#define KEY_H

#include <string>
#include <fstream>

/**
 * function to handle the keystroke translation
 */
class Key {
public:
  explicit Key(const std::string& fname);
  static std::string translateKey(int key);
  static bool shift_caps_upper();
};


#endif //KEY_H
