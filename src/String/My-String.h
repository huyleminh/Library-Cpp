#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>
#include <string>

#define this (*this)

typedef const std::string& ConstBaseReference;
typedef const str::String& ConstReference;
typedef char Element;
typedef size_t SizeType;

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
		String operator+ (ConstReference str) const;

        String& operator+= (Element c);
        String& operator+= (const Element* s);
		String& operator+= (ConstBaseReference str);
		String& operator+= (ConstReference str);


		Element& operator[] (int pos);
		const Element& operator[] (int pos) const;

        // Add a `left` Elementacter at the beginning of `right` string.
        friend String operator+ (Element left, const String& right);

        // Add an `left` array Elementacter at the beginning of `right` string.
        friend String operator+ (const Element* left, const String& right);

        // Add a `left` string at the beginning of `right` string.
        friend String operator+ (ConstBaseReference left, const String& right);

        friend ostream& operator<< (ostream& outDev, ConstReference str);
        friend istream& operator>> (istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str);
        friend istream& getline(istream& inDev, String& str, Element delim);


        //TODO: On branch: relation operators: not finish 
        //Equal to: 
        bool operator ==(ConstBaseReference str);
        friend bool operator ==(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator ==(const Element* ch);
        friend bool operator ==(const Element* ch, const str::String str);

        bool operator ==(ConstReference str);


        //Not equal
        bool operator !=(ConstBaseReference str);
        friend bool operator !=(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator !=(const Element* ch);
        friend bool operator !=(const Element* ch, const str::String str);

        bool operator !=(ConstReference str);


        //Greater than 
        bool operator >(ConstBaseReference str);
        friend bool operator >(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator >(const Element* ch);
        friend bool operator >(const Element* ch, const str::String str);

        bool operator >(ConstReference str);


        //Less than 
        bool operator <(ConstBaseReference str);
        friend bool operator <(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator <(const Element* ch);
        friend bool operator <(const Element* ch, const str::String str);

        bool operator <(ConstReference str);


        //Greater than or equal to
        bool operator >=(ConstBaseReference str);
        friend bool operator >=(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator >=(const Element* ch);
        friend bool operator >=(const Element* ch, const str::String str);

        bool operator >=(ConstReference str);


        //Less than or equal to 
        bool operator <=(ConstBaseReference str);
        friend bool operator <=(ConstBaseReference leftStr, ConstReference rightStr);

        bool operator <=(const Element* ch);
        friend bool operator <=(const Element* ch, const str::String str);

        bool operator <=(ConstReference str);
	};
}

#endif // !_MY_STRING_H_
