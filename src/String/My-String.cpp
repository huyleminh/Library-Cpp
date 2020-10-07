#include "My-String.h"

namespace str {
// Defaut constructor.
String::String() {}


String::String(char c, const int& reatingCount) {
    // std::string tmp(reatingCount, c);
    // this._data = tmp;
}

String::String(const char* s) {
    this._data = s;
}

String::String(const std::string &str) {
    this._data = str;
}


// Copy constructor.
String::String(const String &str) {
    this._data = str._data;
}

String::String(const char* ch) {
    this._data = ch;
}

String &String::operator=(const std::string &str) {
    this._data = str;
    return this;
}

String &String::operator=(const String &str) {
    this._data = str._data;
    return this;
}

String String::operator+(const std::string &str) {
    String result = "";
    result._data += str;
    return result;
}

String String::operator+(const String &str) {
    String result = "";
    result._data += str._data;
    return result;
}

String &String ::operator+=(const std::string &str) {
    this._data += str;
    return this;
}

String &String ::operator+=(const String &str) {
    this._data += str._data;
    return this;
}

String &String ::operator+=(const char& ch) {
    this._data += ch;
    return this;
}

char& String::operator[](const int& pos) {
    return this._data[pos];
}

const char& String::operator[](const int& pos) const {
    return this._data[pos];
}
}