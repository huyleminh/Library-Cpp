#include "My-String.h"

str::String::String() {}

str::String::String(const std::string &str) {
    this->_data = str;
}

str::String::String(const str::String &str) {
    this->_data = str._data;
}

str::String::String(const char* ch) {
    this->_data = ch;
}

str::String &str::String::operator=(const std::string &str) {
    this->_data = str;
    return *this;
}

str::String &str::String::operator=(const str::String &str) {
    this->_data = str._data;
    return *this;
}

str::String str::String::operator+(const std::string &str) {
    str::String result = "";
    result._data += str;
    return result;
}

str::String str::String::operator+(const str::String &str) {
    str::String result = "";
    result._data += str._data;
    return result;
}

str::String &str::String ::operator+=(const std::string &str) {
    this->_data += str;
    return *this;
}

str::String &str::String ::operator+=(const str::String &str) {
    this->_data += str._data;
    return *this;
}

str::String &str::String ::operator+=(const char& ch) {
    this->_data += ch;
    return *this;
}

char& str::String::operator[](const int& pos) {
    return this->_data[pos];
}

const char& str::String::operator[](const int& pos) const {
    return this->_data[pos];
}
