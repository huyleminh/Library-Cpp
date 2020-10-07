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

str::String str::String::operator+(const std::string &str) const {
    str::String result = "";
    result._data += str;
    return result;
}

str::String str::String::operator+(const str::String &str) const {
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

str::String &str::String ::operator+=(char ch) {
    this->_data += ch;
    return *this;
}

char& str::String::operator[](int pos) {
    return this->_data[pos];
}

const char& str::String::operator[](int pos) const {
    return this->_data[pos];
}

namespace str {
    String operator+ (char left, const String& right) {
        return String(left + right._data);
    }

    String operator+ (const char* left, const String& right) {
        return String(left + right._data);
    }

    String operator+ (const std::string& left, const String& right) {
        return String(left + right._data);
    }
    
    ostream& operator<< (ostream& outDev, const str::String& str) {
        outDev << str._data;
        return outDev;
    }

    istream& operator>> (istream& inDev, String& str) {
        inDev >> str._data;
        return inDev;
    }

    istream& getline(istream& inDev, String& str) {
        getline(inDev, str._data);
        return inDev;
    }

    istream& getline(istream& inDev, String& str, char delim) {
        getline(inDev, str._data, delim);
        return inDev;
    }
}
