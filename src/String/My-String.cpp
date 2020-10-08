#include "My-String.h"

// Defaut constructor.
str::String::String() {}

str::String::String(char c, const int& repeatingCount) {
    for (int i = 0; i < repeatingCount; i++) 
        this._data += c;
}

str::String::String(const char* s) {
    this._data = s;
}

str::String::String(const std::string &str) {
    this._data = str;
}

// Copy constructor.
str::String::String(const str::String &str) {
    this._data = str._data;
}

// Assignment operator
str::String &str::String::operator=(const std::string &str) {
    this._data = str;
    return this;
}

// Member operator
str::String str::String::operator+(char c) const {
    str::String result = "";
    result._data += c;
    return result;
}

str::String str::String::operator+(const char* s) const {
    str::String result = "";
    result._data += s;
    return result;
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


str::String &str::String ::operator+=(char ch) {
    this._data += ch;
    return this;
}

str::String& str::String::operator+=(const char* s) {
    this._data += s;
    return this;
}

str::String &str::String ::operator+=(const std::string &str) {
    this._data += str;
    return this;
}

str::String &str::String ::operator+=(const str::String &str) {
    this._data += str._data;
    return this;
}

char& str::String::operator[](int pos) {
    return this._data[pos];
}

const char& str::String::operator[](int pos) const {
    return this._data[pos];
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
