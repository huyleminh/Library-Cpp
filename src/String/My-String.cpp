#include "My-String.h"

// Defaut constructor.
str::String::String() {}

str::String::String(Element c, const int& repeatingCount) {
    for (int i = 0; i < repeatingCount; i++) 
        this._data += c;
}

str::String::String(const Element* s) {
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
str::String& str::String::operator=(Element c) {
    this._data = c;
    return this;
}

str::String& str::String::operator=(const Element* s) {
    this._data = s;
    return this;
}

str::String &str::String::operator=(const std::string &str) {
    this._data = str;
    return this;
}

// Member operator
str::String str::String::operator+(Element c) const {
    str::String result = "";
    result._data += c;
    return result;
}

str::String str::String::operator+(const Element* s) const {
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


str::String &str::String ::operator+=(Element ch) {
    this._data += ch;
    return this;
}

str::String& str::String::operator+=(const Element* s) {
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

Element& str::String::operator[](int pos) {
    return this._data[pos];
}

const Element& str::String::operator[](int pos) const {
    return this._data[pos];
}

namespace str {
    String operator+ (Element left, const String& right) {
        return String(left + right._data);
    }

    String operator+ (const Element* left, const String& right) {
        return String(left + right._data);
    }

    String operator+ (ConstBaseReference left, const String& right) {
        return String(left + right._data);
    }
    
    ostream& operator<< (ostream& outDev, ConstReference str) {
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

    istream& getline(istream& inDev, String& str, Element delim) {
        getline(inDev, str._data, delim);
        return inDev;
    }
}

//TODO new branch: 
//Equal to: 
bool str::String::operator ==(ConstBaseReference str) {
    return this._data == str;
}

bool str::String::operator ==(const Element* ch) {
    return this._data == ch;
}

bool str::String::operator ==(const str::String& str) {
    return this._data == str._data;
}

//Not equal
bool str::String::operator !=(ConstBaseReference str) {
    return this._data != str;
}

bool str::String::operator !=(const Element* ch) {
    return this._data != ch;
}

bool str::String::operator !=(const str::String& str) {
    return this._data != str._data;
}

//Greater than
bool str::String::operator >(ConstBaseReference str) {
    return this._data > str;
}

bool str::String::operator >(const Element* ch) {
    return this._data > ch;
}

bool str::String::operator >(const str::String& str) {
    return this._data > str._data;
}

//Less than
bool str::String::operator <(ConstBaseReference str) {
    return this._data < str;
}

bool str::String::operator <(const Element* ch) {
    return this._data < ch;
}

bool str::String::operator <(const str::String& str) {
    return this._data < str._data;
}

//Greater than or equal to
bool str::String::operator >=(ConstBaseReference str) {
    return this._data >= str;
}

bool str::String::operator >=(const Element* ch) {
    return this._data >= ch;
}

bool str::String::operator >=(const str::String& str) {
    return this._data >= str._data;
}

//Less than or equal to
bool str::String::operator <=(ConstBaseReference str) {
    return this._data <= str;
}

bool str::String::operator <=(const Element* ch) {
    return this._data <= ch;
}

bool str::String::operator <=(const str::String& str) {
    return this._data <= str._data;
}

namespace str {
    bool operator ==(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr == rightStr._data;
    }

    bool operator ==(const Element* ch, const str::String& str) {
        return str._data == ch;
    }


    bool operator !=(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr != rightStr._data;
    }

    bool operator !=(const Element* ch, const str::String& str) {
        return ch != str._data;
    }


    bool operator >(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr > rightStr._data;
    }

    bool operator >(const Element* ch, const str::String& str) {
        return ch > str._data;
    }


    bool operator <(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr < rightStr._data;
    }

    bool operator <(const Element* ch, const str::String& str) {
        return ch < str._data;
    }


    bool operator >=(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr >= rightStr._data;
    }

    bool operator >=(const Element* ch, const str::String& str) {
        return ch >= str._data;
    }


    bool operator <=(ConstBaseReference leftStr, const str::String& rightStr) {
        return leftStr <= rightStr._data;
    }

    bool operator <=(const Element* ch, const str::String& str) {
        return ch <= str._data;
    }
}