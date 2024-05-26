#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <fstream>
#include <filesystem>

class FileHandler {
public:
  explicit FileHandler(const std::string &fname);
  std::string read();
  void write(const std::string &data);
  bool isOpen();
  void clear();
  ~FileHandler();

private:
  std::ofstream fw_stream; // writing stream
  std::ifstream fr_stream; // reading stream
  void checkIfOpen();
};

#endif //FILEHANDLER_H