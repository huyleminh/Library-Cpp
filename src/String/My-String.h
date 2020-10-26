#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>
#include <string>

#define this (*this)

typedef const       std::string& ConstBaseReference;
typedef char        Element;
typedef size_t      SizeType;

using namespace std;

namespace str {
	class String {
	protected:
		std::string _data;

	public:
        // Defaut constructor.
        String();

        String(Element c, const int &repeatingCount = 1);
        String(const Element* s);
        String(ConstBaseReference str);

        // Copy constructor.
        String(const String& str);


		// Assignment operator
        String& operator= (Element c);
        String& operator= (const Element* s);
        String& operator= (ConstBaseReference str);


		// Member operator
        String operator+ (Element c) const;
        String operator+ (const Element* s) const; 
		String operator+ (ConstBaseReference str) const;
		String operator+ (const String &str) const;

        String& operator+= (Element c);
        String& operator+= (const Element* s);
		String& operator+= (ConstBaseReference str);
		String& operator+= (const String &str);


		Element& operator[] (int pos);
		const Element& operator[] (int pos) const;

        // Add a `left` character at the beginning of `right` string.
        friend String operator+ (Element left, const String& right);

        // Add an `left` array character at the beginning of `right` string.
        friend String operator+ (const Element* left, const String& right);

        // Add a `left` string at the beginning of `right` string.
        friend String operator+ (ConstBaseReference left, const String& right);

        friend ostream& operator<< (ostream& outDev, const String &str);
        friend istream& operator>> (istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str, Element delim);


        //TODO: On branch: relation operators: not finish 
        //Equal to: 
        bool operator ==(ConstBaseReference str);
        friend bool operator ==(ConstBaseReference leftStr, const String &rightStr);

        bool operator ==(const Element* ch);
        friend bool operator ==(const Element* ch, const str::String str);

        bool operator ==(const String &str);


        //Not equal
        bool operator !=(ConstBaseReference str);
        friend bool operator !=(ConstBaseReference leftStr, const String &rightStr);

        bool operator !=(const Element* ch);
        friend bool operator !=(const Element* ch, const str::String str);

        bool operator !=(const String &str);


        //Greater than 
        bool operator >(ConstBaseReference str);
        friend bool operator >(ConstBaseReference leftStr, const String &rightStr);

        bool operator >(const Element* ch);
        friend bool operator >(const Element* ch, const str::String str);

        bool operator >(const String &str);


        //Less than 
        bool operator <(ConstBaseReference str);
        friend bool operator <(ConstBaseReference leftStr, const String &rightStr);

        bool operator <(const Element* ch);
        friend bool operator <(const Element* ch, const str::String str);

        bool operator <(const String &str);


        //Greater than or equal to
        bool operator >=(ConstBaseReference str);
        friend bool operator >=(ConstBaseReference leftStr, const String &rightStr);

        bool operator >=(const Element* ch);
        friend bool operator >=(const Element* ch, const str::String str);

        bool operator >=(const String &str);


        //Less than or equal to 
        bool operator <=(ConstBaseReference str);
        friend bool operator <=(ConstBaseReference leftStr, const String &rightStr);

        bool operator <=(const Element* ch);
        friend bool operator <=(const Element* ch, const str::String str);

        bool operator <=(const String &str);
	};
}

#endif // !_MY_STRING_H_
