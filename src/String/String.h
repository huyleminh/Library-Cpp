#ifndef _MOD_LIB_STRING_H_
#define _MOD_LIB_STRING_H_

#include <iostream>
#include <string>
#include "../TypeAlias.h"

using namespace std;

namespace modlib {
	class String {
	private:
		string _data;

        // handle input, input negative.

	public:
        // --------------------------------------------------------------------
        // |                                                                  |
        // |                            Type alias                            |
        // |                                                                  |
        // --------------------------------------------------------------------


        typedef UInt64                              SizeType;

        typedef char                                Element;
        typedef char*                               CharacterArray;
        typedef const char*                         ConstCharacterArray;
        typedef const string&                       ConstBaseReference;        
        typedef modlib::String&                     Reference;
        typedef const modlib::String&               ConstReference;

        typedef string::iterator                    Iterator;
        typedef string::const_iterator              ConstIterator;
        typedef string::reverse_iterator            ReverseIterator;
        typedef string::const_reverse_iterator      ConstReverseIterator;

        // --------------------------------------------------------------------
        




        // --------------------------------------------------------------------
        // |                                                                  |
        // |                         Define values                            |
        // |                                                                  |
        // --------------------------------------------------------------------


        static const SizeType NoPosition;

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                          Initializes                             |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Default constructor.
        String();

        // Initialize a string with `repeatingCount` consecutive copies of character `c`.
        String(Element c, SizeType repeatingCount = 1);

        // Initialize a string with a pointer to the character array.
        String(ConstCharacterArray s);

        // Initialize a string with another string (string type).
        String(ConstBaseReference str);

        // Copy constructor.
        String(ConstReference str);

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                             Capacity                             |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Check if the string is empty or not.
        bool isEmpty() const;

        // Returns the length of the string.
        SizeType length() const;

        // --------------------------------------------------------------------
        
        
        
        
        
        // --------------------------------------------------------------------
        // |                                                                  |
        // |                            Iterators                             |
        // |                                                                  |
        // --------------------------------------------------------------------

        // Returns Iterator to beginning.
        Iterator begin();

        // Returns Iterator to end.
        Iterator end();

        // Returns ConstIterator to beginning.
        ConstIterator begin() const;

        // Returns ConstIterator to end.
        ConstIterator end() const;

        // Returns ReverseIterator to reverse beginning.
        ReverseIterator reverseBegin();
        
        // Returns ReverseIterator to reverse end.
        ReverseIterator reverseEnd();

        // Returns ConstReverseIterator to reverse beginning.
        ConstReverseIterator reverseBegin() const;
        
        // Returns ConstReverseIterator to reverse end.
        ConstReverseIterator reverseEnd() const;

        // Returns ConstIterator to beginning.
        ConstIterator constBegin() const;
        
        // Returns ConstIterator to end.
        ConstIterator constEnd() const;

        // Returns ConstReverseIterator to reverse beginning.
        ConstReverseIterator constReverseBegin() const;
        
        // Returns ConstReverseIterator to reverse end.
        ConstReverseIterator constReverseEnd() const;

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                            Change                                |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Returns a uppercase version of the string.
        String uppercase() const;

        // Returns a lowercase version of the string.
        String lowercase() const;

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                            Remove                                |
        // |                                                                  |
        // --------------------------------------------------------------------

        // Remove all string
        void removeAll();

        // Remove a character
        void remove(const Element& ch);

        // Remove a character at index
        void removeAt(SizeType pos);

        // Remove a character at iterator
        void removeAt(ConstIterator iter);

        // Remove substring [start, end - 1].
        void removeSubrange(SizeType start, SizeType end);

        // Remove substring [start, end - 1].
        void removeSubrange(ConstIterator start, ConstIterator end);

        // Remove substring [0, end - 1].
        void removePrefix(SizeType end);

        // Remove substring [0, end - 1].
        void removePrefix(ConstIterator end);

        // Remove substring [start, length - 1].
        void removeSuffix(SizeType start);

        // Remove substring [start, length - 1].
        void removeSuffix(ConstIterator start);

        // Remove the first element if the string is not empty.
        void removeFirst();

        // Remove the last element if the string is not empty.
        void removeLast();

        // Remove all whitespaces at the beginning and the end of the string.
        String trim(bool left = true, bool right = true) const;
        
        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |           Assignment, Addition, Brackets operators.              |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Assignment operator.
        String& operator= (Element c);
        String& operator= (ConstCharacterArray s);
        String& operator= (ConstBaseReference str);

        // Add a character, character array and string at the end of this string.
        String operator+ (Element c) const;
        String operator+ (ConstCharacterArray s) const; 
		String operator+ (ConstBaseReference str) const;
		String operator+ (ConstReference str) const;

        String& operator+= (Element c);
        String& operator+= (ConstCharacterArray s);
		String& operator+= (ConstBaseReference str);
		String& operator+= (ConstReference str);

        Element& operator[] (SizeType pos);
		const Element& operator[] (SizeType pos) const;

        // --------------------------------------------------------------------




        // --------------------------------------------------------------------
        // |                                                                  |
        // |                        Addition methods                          |
        // |                                                                  |
        // --------------------------------------------------------------------



        //Append a copy of a std::string
        String& append(ConstBaseReference str);

        //Append a copy of a modlib::String
        String& append(ConstReference str);

        //Append a copy of a sub string in std::string
        String& append(ConstBaseReference str, SizeType beginPos, SizeType len);

        //Append a copy of a sub string in modlib::String
        String& append(ConstReference str, SizeType beginPos, SizeType len);

        //Append a copy of the characters sequence
        String& append(ConstCharacterArray seq);

        //Append a copy of n characters in the array of characters points by seq
        String& append(ConstCharacterArray seq, SizeType n);

        //Append n consecutive copies of character c
        String& append(SizeType n, Element c);

        //Append a copy of a sequence in range [begin, end)
        template<class InIterator>
            String& append(InIterator begin, InIterator end) {
            this->_data.append(begin, end);
            return *this;
        }

        //! Need to review
        //Appends a copy of each of the characters in il, in the same order
        String& append (initializer_list<char> il);

        // --------------------------------------------------------------------




        // --------------------------------------------------------------------
        // |                                                                  |
        // |                         Insert methods                           |
        // |                                                                  |
        // --------------------------------------------------------------------



        //Insert additional characters right before the input position pos

        //Insert a copy of std::string
        String& insert(SizeType pos, ConstBaseReference str);

        //Insert a copy of  modlib::String 
        String& insert(SizeType pos, ConstReference str);

        //Insert a copy of sub string of std::string
        String& insert(SizeType pos, ConstBaseReference str, SizeType begin, SizeType len);

        //Insert a copy of sub string of modlib::String
        String& insert(SizeType pos, ConstReference str, SizeType begin, SizeType len);

        //Insert a copy of the characters sequence
        String& insert(SizeType pos, ConstCharacterArray s);

        //Insert a copy of n characters in the array of characters points by seq
        String& insert(SizeType pos, ConstCharacterArray seq, SizeType n);

        //Insert n consecutive copies of character ch
        String& insert(SizeType pos, SizeType n, Element ch);

        //Insert n consecutive copies of character ch and return the iterator at the first character inserted
        Iterator insert(ConstIterator it, SizeType n, Element ch);

        //Insert a single character at the input iterator
        Iterator insert(ConstIterator it, Element ch);

        //Insert a copy of a sequence in range [begin, end) at the input iterator
        template<class InIterator>
        Iterator insert (Iterator p, InIterator first, InIterator last) {
            Iterator _it = this->_data.insert(p, first, last);
            return _it;
        }

        //! Need to review
        // Insert a copy of each of the characters in il, in the same order
        String& insert(ConstIterator p, initializer_list<char> il);


        // --------------------------------------------------------------------



        // --------------------------------------------------------------------
        // |                                                                  |
        // |                        Push method                               |
        // |                                                                  |
        // --------------------------------------------------------------------

        void push(Element ch);

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                     Comparison operators                         |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Equal to.
        // bool operator ==(Element c);
        bool operator ==(ConstCharacterArray s) const;
        bool operator ==(ConstBaseReference str) const;

        // Not equal to.
        // bool operator !=(Element c);
        bool operator !=(ConstCharacterArray s) const;
        bool operator !=(ConstBaseReference str) const;

        // Greater than.
        // bool operator >(Element c);
        bool operator >(ConstCharacterArray s) const;
        bool operator >(ConstBaseReference str) const;

        // Less than.
        // bool operator <(Element c);
        bool operator <(ConstCharacterArray s) const;
        bool operator <(ConstBaseReference str) const;

        // Greater than or equal to.
        // bool operator >=(Element c);
        bool operator >=(ConstCharacterArray s) const;
        bool operator >=(ConstBaseReference str) const;

        // Less than or equal to.
        // bool operator <=(Element c);
        bool operator <=(ConstCharacterArray s) const;
        bool operator <=(ConstBaseReference str) const;

        // --------------------------------------------------------------------





        // --------------------------------------------------------------------
        // |                                                                  |
        // |                     Non-member overloads                         |
        // |                                                                  |
        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Comparison operators.

        //TODO: On branch: relation operators: not finish 
        // Equal to.
        // friend bool operator ==(String::Element left, String::ConstReference right);
        friend bool operator ==(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator ==(String::ConstBaseReference left, String::ConstReference right); 
        
        // Not equal to.
        // friend bool operator !=(String::Element left, String::ConstReference right);
        friend bool operator !=(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator !=(String::ConstBaseReference left, String::ConstReference right);

        // Greater than.
        // friend bool operator >(String::Element left, String::ConstReference right);
        friend bool operator >(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator >(String::ConstBaseReference left, String::ConstReference right);

        // Less than.
        // friend bool operator <(String::Element left, String::ConstReference right);
        friend bool operator <(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator <(String::ConstBaseReference left, String::ConstReference right);

        // Greater than or equal to.
        // friend bool operator >=(String::Element left, String::ConstReference right);
        friend bool operator >=(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator >=(String::ConstBaseReference left, String::ConstReference right);

        // Less than or equal to.
        // friend bool operator <=(String::Element left, String::ConstReference right);
        friend bool operator <=(String::ConstCharacterArray left, String::ConstReference right);
        friend bool operator <=(String::ConstBaseReference left, String::ConstReference right);

        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Addition operator.

        // Add a character, character array and string at the beginning of this string.
        friend String operator+ (String::Element left, String::ConstReference right);
        friend String operator+ (String::ConstCharacterArray left, String::ConstReference right);
        friend String operator+ (String::ConstBaseReference left, String::ConstReference right);

        // --------------------------------------------------------------------


        // --------------------------------------------------------------------
        // Input, output operators and methods.

        // Output a string to the output device.
        friend ostream& operator<< (ostream& outDev, String::ConstReference str);

        // Input a string from the input device.
        friend istream& operator>> (istream& inDev, String::Reference str);
        friend istream& getline(istream& inDev, String::Reference str);
        friend istream& getline(istream& inDev, String::Reference str, String::Element delim);

        // --------------------------------------------------------------------



        static char toUpperCharacter(char);
        static char toLowerCharacter(char);

        private:
        void changeCase(Element (*change)(Element));
	};
}

#endif // !_MY_STRING_H_
