#include "My-String.h"

str::String::String() {
	this->_data = "";
}

str::String::String(const std::string& str)
{
    this->_data = str;
}

str::String::String(const str::String& str)
{
    this->_data = str._data;
}

str::String& str::String::operator =(const std::string& str) {
    this->_data = str;
    return *this;
}

str::String& str::String::operator =(const str::String& str) {
    this->_data = str._data;
    return *this;
}
