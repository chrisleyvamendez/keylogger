//
// Created by actua on 5/25/2024.
//
#include "../include/FileHandler.h"

FileHandler::FileHandler(const std::string &fname) {
  const std::filesystem::path path(fname);
  fw_stream.open(path, std::ios::app); // opened the file in append mode
  fr_stream.open(path); // opened the file in read mode
  checkIfOpen();
}

std::string FileHandler::read() {
  checkIfOpen();
  if (!fr_stream.good()) {
    throw std::runtime_error("fr_stream is not in a good state to read");
  }
  std::string data;
  if (!std::getline(fr_stream, data)) {
    throw std::runtime_error("Error reading from file");
  }
  return data;
}

void FileHandler::write(const std::string &data) {
  checkIfOpen();
  fw_stream << data;
  if (fw_stream.fail()) {
    throw std::runtime_error("Error writing to file");
  }
  // flush the stream to write the data to the file
  fw_stream.flush();
}

bool FileHandler::isOpen() { return fw_stream.is_open(); }

void FileHandler::clear() {
  checkIfOpen();
  fw_stream.clear();
  fw_stream.seekp(0, std::ios::beg);
  fw_stream << "";
  fw_stream.clear();
}

FileHandler::~FileHandler() {
  if (fw_stream.is_open()) {
    fw_stream.close();
  }
  if (fr_stream.is_open()) {
    fr_stream.close();
  }
}

void FileHandler::checkIfOpen() {
  if (!fw_stream.is_open() || !fr_stream.is_open()) {
    throw std::runtime_error("File is not open");
  }
}