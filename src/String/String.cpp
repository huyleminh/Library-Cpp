#include "String.h"

namespace modlib {

// Defaut constructor.
String::String() {}

String::String(Element c, const int& repeatingCount) {
    for (int i = 0; i < repeatingCount; i++)
    this->_data += c;
}

String::String(const Element* s) {
    this->_data = s;
}

String::String(const std::string &str) {
    this->_data = str;
}

// Copy constructor.
String::String(ConstReference str) {
    this->_data = str._data;
}

// Assignment operator
String& String::operator=(Element c) {
    this->_data = c;
    return *this;
}

String& String::operator=(const Element* s) {
    this->_data = s;
    return *this;
}

String& String::operator=(ConstBaseReference str) {
    this->_data = str;
    return *this;
}

// Member operator
String String::operator+(Element c) const {
    String result = "";
    result._data += c;
    return result;
}

String String::operator+(const Element* s) const {
    String result = "";
    result._data += s;
    return result;
}

String String::operator+(ConstBaseReference str) const {
    String result = "";
    result._data += str;
    return result;
}

String String::operator+(ConstReference str) const {
    String result = "";
    result._data += str._data;
    return result;
}


String& String::operator+=(Element ch) {
    this->_data += ch;
    return *this;
}

String& String::operator+=(const Element* s) {
    this->_data += s;
    return *this;
}

String& String ::operator+=(ConstBaseReference str) {
    this->_data += str;
    return *this;
}

String& String::operator+=(ConstReference str) {
    this->_data += str._data;
    return *this;
}

String::Element& String::operator[](int pos) {
    return this->_data[pos];
}

const String::Element& String::operator[](int pos) const {
    return this->_data[pos];
}

String operator+ (String::Element left, const String& right) {
    return String(left + right._data);
}

String operator+ (const String::Element* left, const String& right) {
    return String(left + right._data);
}

String operator+ (String::ConstBaseReference left, String::ConstReference right) {
    return String(left + right._data);
}

ostream& operator<< (ostream& outDev, String::ConstReference str) {
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

istream& getline(istream& inDev, String& str, String::Element delim) {
    getline(inDev, str._data, delim);
    return inDev;
}

//TODO new branch: 
//Equal to: 
bool String::operator ==(ConstBaseReference str) {
    return this->_data == str;
}

bool String::operator ==(const Element* ch) {
    return this->_data == ch;
}

bool String::operator ==(ConstReference str) {
    return this->_data == str._data;
}

//Not equal
bool modlib::String::operator !=(ConstBaseReference str) {
    return this->_data != str;
}

bool modlib::String::operator !=(const Element* ch) {
    return this->_data != ch;
}

bool modlib::String::operator !=(ConstReference str) {
    return this->_data != str._data;
}

//Greater than
bool modlib::String::operator >(ConstBaseReference str) {
    return this->_data > str;
}

bool modlib::String::operator >(const Element* ch) {
    return this->_data > ch;
}

bool modlib::String::operator >(ConstReference str) {
    return this->_data > str._data;
}

//Less than
bool modlib::String::operator <(ConstBaseReference str) {
    return this->_data < str;
}

bool modlib::String::operator <(const Element* ch) {
    return this->_data < ch;
}

bool modlib::String::operator <(ConstReference str) {
    return this->_data < str._data;
}

//Greater than or equal to
bool modlib::String::operator >=(ConstBaseReference str) {
    return this->_data >= str;
}

bool modlib::String::operator >=(const Element* ch) {
    return this->_data >= ch;
}

bool modlib::String::operator >=(ConstReference str) {
    return this->_data >= str._data;
}

//Less than or equal to
bool modlib::String::operator <=(ConstBaseReference str) {
    return this->_data <= str;
}

bool modlib::String::operator <=(const Element* ch) {
    return this->_data <= ch;
}

bool modlib::String::operator <=(ConstReference str) {
    return this->_data <= str._data;
}

bool operator ==(String::ConstBaseReference left, String::ConstReference right) {
    return left == right._data;
}

bool operator ==(const String::Element* ch, String::ConstReference str) {
    return str._data == ch;
}


bool operator !=(String::ConstBaseReference left, String::ConstReference right) {
    return left != right._data;
}

bool operator !=(const String::Element* ch, String::ConstReference str) {
    return ch != str._data;
}


bool operator >(String::ConstBaseReference left, String::ConstReference right) {
    return left > right._data;
}

bool operator >(const String::Element* ch, String::ConstReference str) {
    return ch > str._data;
}


bool operator <(String::ConstBaseReference left, String::ConstReference right) {
    return left < right._data;
}

bool operator <(const String::Element* ch, String::ConstReference str) {
    return ch < str._data;
}


bool operator >=(String::ConstBaseReference left, String::ConstReference right) {
    return left >= right._data;
}

bool operator >=(const String::Element* ch, String::ConstReference str) {
    return ch >= str._data;
}

bool operator <=(String::ConstBaseReference left, String::ConstReference right) {
    return left <= right._data;
}

bool operator <=(const String::Element* ch, String::ConstReference str) {
    return ch <= str._data;
}
}
