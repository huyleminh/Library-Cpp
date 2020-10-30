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


        typedef const string&           ConstBaseReference;
        typedef char                    Element;
        typedef const char*             ConstCharacterArray;
        typedef char*                   CharacterArray;
        typedef UInt64                  SizeType;
        typedef modlib::String&         Reference;
        typedef const modlib::String&   ConstReference;

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
        // |                            Remove                                |
        // |                                                                  |
        // --------------------------------------------------------------------


        // Remove substring [start, end - 1].
        void removeSubrange(SizeType start, SizeType end);

        // Remove substring [0, end - 1].
        void removePrefix(SizeType end);

        // Remove substring [start, ].
        void removeSuffix(SizeType start);

        // Remove the first element if the string is empty.
        void removeFirst();

        // Remove the last element if the string is empty.
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