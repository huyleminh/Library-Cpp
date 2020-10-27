#ifndef _MOD_LIB_STRING_H_
#define _MOD_LIB_STRING_H_

#include <iostream>
#include <string>

using namespace std;

namespace modlib {
	class String {
	private:
		string _data;

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
        typedef size_t                  SizeType;
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
        String(Element c, int repeatingCount = 1);

        // Initialize a string with a pointer to the character array.
        String(ConstCharacterArray s);

        // Initialize a string with another string (string type).
        String(ConstBaseReference str);

        // Copy constructor.
        String(ConstReference str);

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
        // |                     Comparision operators                        |
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
        // Comparision operators.

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
        friend istream& operator>> (istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str, String::Element delim);

        // --------------------------------------------------------------------
        // --------------------------------------------------------------------
	};
}

#endif // !_MY_STRING_H_
