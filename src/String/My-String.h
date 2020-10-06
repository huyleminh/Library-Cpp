#ifndef _MY_STRING_H_
#define _MY_STRING_H_

#include <string>

namespace str {
	class String {
	protected:
		std::string _data;
	public:
		String();
		~String() {};

		//Copy constructor
		String(const std::string& str);
		String(const str::String& str);
		String(const char* ch);

		//Assignment operator
		String& operator =(const std::string& str);
		String& operator =(const str::String& str);

		//Member operator
		String operator +(const std::string& str);
		String operator +(const str::String& str);

		String& operator +=(const std::string& str);
		String& operator +=(const str::String& str);
		String& operator +=(const char& ch);

		char& operator [](const int& pos);
		const char& operator [](const int& pos) const;

	};
}

#endif // !_MY_STRING_H_
