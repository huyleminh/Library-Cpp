#ifndef _MOD_LIB_STRING_H_
#define _MOD_LIB_STRING_H_

#include <iostream>
#include <string>
#include "/Users/lehoanganh/Desktop/HoangAnh/Library-Cpp/src/TypeAlias.h"

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
        // |                            Remove                                |
        // |                                                                  |
        // --------------------------------------------------------------------


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
        String trim() const;
        
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
        // |                     Comparison operators                        |
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
        // --------------------------------------------------------------------
	};
}

#endif // !_MY_STRING_H_
