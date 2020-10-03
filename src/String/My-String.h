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
        
        	String& operator =(const std::string& str);
        	String& operator =(const str::String& str);
	};
}

#endif // !_MY_STRING_H_
