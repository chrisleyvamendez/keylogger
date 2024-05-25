//
// Created by actua on 5/21/2024.
//
#include "../include/Key.h"
#include <windows.h>
#include <iostream>


// Constructor to open the file
// pass the file name by reference const means that the file name cannot be changed
Key::Key(const std::string &fname) {}

// Translate the key to a string to log
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
       keyStr = static_cast<char>(key);

   }
   return keyStr;
}