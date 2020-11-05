#include "String.h"

using namespace modlib;


namespace modlib {


    void String::changeCase(Element(*change)(Element c)) {
        for (Element& c : _data)
            c = change(c);
    }


    // --------------------------------------------------------------------
    // |                                                                  |
    // |                         Define values                            |
    // |                                                                  |
    // --------------------------------------------------------------------


    const String::SizeType NoPosition = string::npos;

    // --------------------------------------------------------------------





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
    // |                            Iterators                             |
    // |                                                                  |
    // --------------------------------------------------------------------

    String::Iterator String::begin() {
        return _data.begin();
    }

    String::Iterator String::end() {
        return _data.end();
    }

    String::ConstIterator String::begin() const {
        return _data.begin();
    }

    String::ConstIterator String::end() const {
        return _data.end();
    }

    String::ReverseIterator String::reverseBegin() {
        return _data.rbegin();
    }

    String::ReverseIterator String::reverseEnd() {
        return _data.rend();
    }

    String::ConstReverseIterator String::reverseBegin() const {
        return _data.rbegin();
    }

    String::ConstReverseIterator String::reverseEnd() const {
        return _data.rend();
    }

    String::ConstIterator String::constBegin() const {
        return _data.cbegin();
    }

    String::ConstIterator String::constEnd() const {
        return _data.cend();
    }

    String::ConstReverseIterator String::constReverseBegin() const {
        return _data.crbegin();
    }

    String::ConstReverseIterator String::constReverseEnd() const {
        return _data.crend();
    }

    // --------------------------------------------------------------------





    // --------------------------------------------------------------------
    // |                                                                  |
    // |                            Change                                |
    // |                                                                  |
    // --------------------------------------------------------------------


    String String::uppercase() const {
        String upper = _data;
        upper.changeCase(String::toUpperCharacter);

        return upper;
    }

    String String::lowercase() const {
        String upper = _data;
        upper.changeCase(String::toLowerCharacter);

        return upper;
    }

    // --------------------------------------------------------------------





    // --------------------------------------------------------------------
    // |                                                                  |
    // |                            Remove                                |
    // |                                                                  |
    // --------------------------------------------------------------------

    void String::removeAll() {
        this->_data.erase(this->_data.begin(), this->end());
    }

    //Remove a character
    void String::remove(const String::Element& ch) {
        SizeType pos = this->_data.rfind(ch);
            this->removeAt(pos);
    }

    //Remove a character at index
    void String::removeAt(String::SizeType pos) {
        if (pos < 0 || pos >= this->_data.length())
            return;
        this->_data.erase(pos, pos + 1);
    }

    //Remove a character at iterator
    void String::removeAt(String::ConstIterator iter) {
        this->removeSubrange(iter, iter + 1);
    }

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
        removeSubrange(start, _data.length());
    }

    void String::removeSuffix(ConstIterator start) {
        removeSubrange(start, _data.end());
    }

    void String::removeFirst() {
        // if (_data.empty())
            // removeAt(0);
    }

    void String::removeLast() {
        // if (_data.empty())
            // removeAt(_data.length() - 1);
    }

    String String::trim(bool left, bool right) const {
        string res = _data;

        if (left) {
            const size_t endLeft = res.find_first_not_of(' ');
            if (endLeft != string::npos)
                res.erase(0, endLeft); // remove all whitespaces at the beginning of the string.
        }

        if (right) {
            const size_t startRight = res.find_last_not_of(' ');
            if (startRight != string::npos && startRight != res.length() - 1)
                res.erase(startRight + 1); // remove all whitespaces at the end of the string.
        }

        return String(res);
    }

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
    // |                        Addition methods                          |
    // |                                                                  |
    // --------------------------------------------------------------------



    //Append a copy of a std::string
    String& String::append(ConstBaseReference str) {
        this->_data.append(str);
        return *this;
    }

    //Append a copy of a modlib::String
    String& String::append(ConstReference str) {
        this->_data.append(str._data);
        return *this;
    }


    //Append a copy of a sub string in std::string
    String& String::append(ConstBaseReference str, SizeType beginPos, SizeType len) {
        this->_data.append(str, beginPos, len);
        return *this;
    }


    //Append a copy of a sub string in modlic::String
    String& String::append(ConstReference str, SizeType beginPos, SizeType len) {
        this->_data.append(str._data, beginPos, len);
        return *this;
    }


    //Append a copy of the characters sequence
    String& String::append(ConstCharacterArray seq) {
        this->_data.append(seq);
        return *this;
    }


    //Append a copy of n characters in the array of characters points by seq
    String& String::append(ConstCharacterArray seq, SizeType n) {
        this->_data.append(seq, n);
        return *this;
    }


    //Append n consecutive copies of character c.
    String& String::append(SizeType n, Element c) {
        this->_data.append(n, c);
        return *this;
    }

    //Appends a copy of each of the characters in il, in the same order
    String& String::append(initializer_list<char> il) {
        this->_data.append(il);
        return *this;
    }

    // --------------------------------------------------------------------




    // --------------------------------------------------------------------
    // |                                                                  |
    // |                         Insert methods                           |
    // |                                                                  |
    // --------------------------------------------------------------------



    //Insert additional characters right before the input position pos

    //Insert a copy of std::string
    String& String::insert(SizeType pos, ConstBaseReference str) {
        this->_data.insert(pos, str);
        return *this;
    }


    //Insert a copy of  modlib::String 
    String& String::insert(SizeType pos, ConstReference str) {
        this->_data.insert(pos, str._data);
        return *this;
    }


    //Insert a copy of sub string of std::string
    String& String::insert(SizeType pos, ConstBaseReference str, SizeType begin, SizeType len) {
        this->_data.insert(pos, str, begin, len);
        return *this;
    }


    //Insert a copy of sub string of modlib::String
    String& String::insert(SizeType pos, ConstReference str, SizeType begin, SizeType len) {
        this->_data.insert(pos, str._data, begin, len);
        return *this;
    }


    //Insert a copy of the characters sequence
    String& String::insert(SizeType pos, ConstCharacterArray s) {
        this->_data.insert(pos, s);
        return *this;
    }


    //Insert a copy of n characters in the array of characters points by seq
    String& String::insert(SizeType pos, ConstCharacterArray seq, SizeType n) {
        this->_data.insert(pos, seq, n);
        return *this;
    }


    //Insert n consecutive copies of character ch
    String& String::insert(SizeType pos, SizeType n, Element ch) {
        this->_data.insert(pos, n, ch);
        return *this;
    }


    //Insert n consecutive copies of character ch and return the iterator at the first character inserted
    String::Iterator String::insert(ConstIterator it, SizeType n, Element ch) {
        String::Iterator _it = this->_data.insert(it, n, ch);
        return _it;
    }

    //Insert a single character at the input iterator
    String::Iterator String::insert(ConstIterator it, Element ch) {
        String::Iterator _it = this->_data.insert(it, ch);
        return _it;
    }

    //! Need to review
    //Inser a copy of each of the characters in il, in the same order
    String& String::insert(ConstIterator p, initializer_list<char> il) {
        this->_data.insert(p, il);
        return *this;
    }



    // --------------------------------------------------------------------



    // --------------------------------------------------------------------
    // |                                                                  |
    // |                        Push method                               |
    // |                                                                  |
    // --------------------------------------------------------------------

    void String::push(Element ch) {
        this->_data.push_back(ch);
    }

    // --------------------------------------------------------------------



    // --------------------------------------------------------------------
    // |                                                                  |
    // |                     Comparison operators                         |
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



    char String::toUpperCharacter(char c) {
        if ('a' <= c && c <= 'z')
            return c - 'a' + 'A';
    }

    char String::toLowerCharacter(char c) {
        if ('A' <= c && c <= 'Z')
            return c - 'A' + 'a';
    }

}