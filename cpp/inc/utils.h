#ifndef Zipsa_Utils
#define Zipsa_Utils

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <limits.h>

std::vector<std::string> tokenize_getline(const std::string& data, const char delimiter = ' ');
bool isNumber(const std::string& str);
std::string trim(const std::string& s);
size_t getFileSize(const char *filename);
std::string getApplicationDirectory();

#endif