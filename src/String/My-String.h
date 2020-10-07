#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <iostream>
#include <string>

#define this (*this)

using namespace std;

namespace str {
	class String {
	protected:
		std::string _data;

	public:
        // Defaut constructor.
        String();

        String(char c, const int &repeatingCount = 1);
        String(const char* s);
        String(const std::string& str);

        // Copy constructor.
        String(const String& str);


		// Assignment operator
        String& operator= (char c);
        String& operator= (const char* s);
        String& operator= (const std::string& str);


		// Member operator
        String operator+ (char c) const;
        String operator+ (const char* s) const;
		String operator+ (const std::string& str) const;
		String operator+ (const str::String& str) const;

        String& operator+= (char c);
        String& operator+= (const char* s);
		String& operator+= (const std::string& str);
		String& operator+= (const str::String& str);


		char& operator[] (int pos);
		const char& operator[] (int pos) const;

        friend String operator+ (char left, const String& right);
        friend String operator+ (const char* left, const String& right);
        friend String operator+ (const std::string& left, const String& right);

        friend ostream& operator<< (ostream& outDev, const String& str);
        friend istream& operator>> (istream& inDev, const String& str);
        friend istream& getline(istream& inDev, const String& str, char delim = '\n');
	};
}

#endif // !_MY_STRING_H_
