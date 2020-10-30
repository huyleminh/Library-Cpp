#include "String.h"

using namespace modlib;


namespace modlib {


// --------------------------------------------------------------------
// |                                                                  |
// |                          Initializes                             |
// |                                                                  |
// --------------------------------------------------------------------


String::String() {}

String::String(Element c, SizeType repeatingCount) {
    _data = string(repeatingCount, c);
}

String::String(ConstCharacterArray s) {
    _data = s;
}

String::String(ConstBaseReference str) {
    _data = str;
}

String::String(ConstReference str) {
    _data = str._data;
}

// --------------------------------------------------------------------





// --------------------------------------------------------------------
// |                                                                  |
// |                             Capacity                             |
// |                                                                  |
// --------------------------------------------------------------------


bool String::isEmpty() const {
    return _data.empty();
}

String::SizeType String::length() const {
    return _data.length();
}

// --------------------------------------------------------------------





// --------------------------------------------------------------------
// |                                                                  |
// |                            Remove                                |
// |                                                                  |
// --------------------------------------------------------------------


void String::removeSubrange(SizeType start, SizeType end) {
    Iterator last = _data.end();

    if (end <= _data.length())
        last = _data.begin() + end;

    removeSubrange(_data.begin() + start, last);
}

void String::removeSubrange(ConstIterator start, ConstIterator end) {
    _data.erase(start, end);
}

void String::removePrefix(SizeType end) {
    removeSubrange(0, end);
}
        
void String::removePrefix(ConstIterator end) {
    removeSubrange(_data.begin(), end);
}
        
void String::removeSuffix(SizeType start) {
    removeSubrange(start, _data.length() - 1);
}
        
void String::removeSuffix(ConstIterator start) {
    removeSubrange(start, _data.end());
}

void String::removeFirst() {
    // check empty
    // remove(0);
}

void String::removeLast() {
    // check empty
    // remove(_data.length() - 1);
}

// String String::trim() const {

// }
        
// --------------------------------------------------------------------

// --------------------------------------------------------------------
// |                                                                  |
// |           Assignment, Addition, Brackets operators.              |
// |                                                                  |
// --------------------------------------------------------------------


String& String::operator=(Element c) {
    _data = c;
    return *this;
}

String& String::operator=(ConstCharacterArray s) {
    _data = s;
    return *this;
}

String& String::operator=(ConstBaseReference str) {
    _data = str;
    return *this;
}

String String::operator+(Element c) const {
    return _data + c;
}

String String::operator+(ConstCharacterArray s) const {
    return _data + s;
}

String String::operator+(ConstBaseReference str) const {
    return _data + str;
}

String String::operator+(ConstReference str) const {
    return _data + str._data;
}

String& String::operator+=(Element c) {
    this->_data += c;
    return *this;
}

String& String::operator+=(ConstCharacterArray s) {
    this->_data += s;
    return *this;
}

String& String::operator+=(ConstBaseReference str) {
    this->_data += str;
    return *this;
}

String& String::operator+=(ConstReference str) {
    this->_data += str._data;
    return *this;
}

String::Element& String::operator[](SizeType pos) {
    return _data.at(pos);
}

const String::Element& String::operator[](SizeType pos) const {
    return _data.at(pos);
}

// --------------------------------------------------------------------





// --------------------------------------------------------------------
// |                                                                  |
// |                     Comparision operators                        |
// |                                                                  |
// --------------------------------------------------------------------


// Equal to.
// bool String::operator ==(Element c) const {
//     if (_data.empty() && c == '\0')
//         return true;
//     if (_data.size() == 1 && _data[0] == c)
//         return true;
//     return false;
// }

bool String::operator ==(ConstCharacterArray s) const {
    return _data == s;
}

bool String::operator ==(ConstBaseReference str) const {
    return _data == str;
}

// Not equal to.
// bool String::operator !=(Element c) const {
//     return !(*this == c);
// }

bool String::operator !=(ConstCharacterArray s) const {
    return _data != s;
}

bool String::operator !=(ConstBaseReference str) const {
    return _data != str;
}

// Greater than.
// bool String::operator >(Element c) const {}

bool String::operator >(ConstCharacterArray s) const {
    return _data > s;
}

bool String::operator >(ConstBaseReference str) const {
    return _data > str;
}


// Less than.
// bool String::operator <(Element c) const {}

bool String::operator <(ConstCharacterArray s) const {
    return _data < s;
}

bool String::operator <(ConstBaseReference str) const {
    return _data < str;
}


// Greater than or equal to.
// bool String::operator >=(Element c) const {}

bool String::operator >=(ConstCharacterArray s) const {
    return _data >= s;
}

bool String::operator >=(ConstBaseReference str) const {
    return _data >= str;
}


// Less than or equal to.
// bool String::operator <=(Element c) const {}

bool String::operator <=(ConstCharacterArray s) const {
    return _data <= s;
}

bool String::operator <=(ConstBaseReference str) const {
    return _data <= str;
}


// --------------------------------------------------------------------





// --------------------------------------------------------------------
// |                                                                  |
// |                     Non-member overloads                         |
// |                                                                  |
// --------------------------------------------------------------------


// --------------------------------------------------------------------
// Comparision operators.

// Equal to.
// bool operator ==(String::Element left, String::ConstReference right);
bool operator ==(String::ConstCharacterArray left, String::ConstReference right) {
    return right == left;
}

bool operator ==(String::ConstBaseReference left, String::ConstReference right) {
    return right == left;
}

// Not equal to.
// bool operator !=(String::Element left, String::ConstReference right) {}

bool operator !=(String::ConstCharacterArray left, String::ConstReference right) {
    return right != left;
}

bool operator !=(String::ConstBaseReference left, String::ConstReference right) {
    return right != left;
}

// Greater than.
// bool operator >(String::Element left, String::ConstReference right) {}

bool operator >(String::ConstCharacterArray left, String::ConstReference right) {
    return right > left;
}

bool operator >(String::ConstBaseReference left, String::ConstReference right) {
    return right > left;
}

// Less than.
// bool operator <(String::Element left, String::ConstReference right) {}

bool operator <(String::ConstCharacterArray left, String::ConstReference right) {
    return right < left;
}

bool operator <(String::ConstBaseReference left, String::ConstReference right) {
    return right < left;
}

// Greater than or equal to.
// bool operator >=(String::Element left, String::ConstReference right) {}

bool operator >=(String::ConstCharacterArray left, String::ConstReference right) {
    return right >= left;
}

bool operator >=(String::ConstBaseReference left, String::ConstReference right) {
    return right >= left;
}

// Less than or equal to.
// bool operator <=(String::Element left, String::ConstReference right) {}

bool operator <=(String::ConstCharacterArray left, String::ConstReference right) {
    return right <= left;
}

bool operator <=(String::ConstBaseReference left, String::ConstReference right) {
    return right <= left;
}

// --------------------------------------------------------------------


// --------------------------------------------------------------------
// Addition operator.

// Add a character, character array and string at the beginning of this string.
String operator+ (String::Element left, String::ConstReference right) {
    return left + right._data;
}

String operator+ (String::ConstCharacterArray left, String::ConstReference right) {
    return left + right._data;
}

String operator+ (String::ConstBaseReference left, String::ConstReference right) {
    return left + right._data;
}

// --------------------------------------------------------------------


// --------------------------------------------------------------------
// Input, output operators and methods.

// Output a string to the output device.
ostream& operator<< (ostream& outDev, String::ConstReference str) {
    outDev << str._data;
    return outDev;
}

// Input a string from the input device.
istream& operator>> (istream& inDev, String::Reference str) {
    inDev >> str._data;
    return inDev;
}

istream& getline(istream& inDev, String::Reference str) {
    getline(inDev, str._data);
    return inDev;
}

istream& getline(istream& inDev, String::Reference str, String::Element delim) {
    getline(inDev, str._data, delim);
    return inDev;
}

// --------------------------------------------------------------------
// --------------------------------------------------------------------
}
