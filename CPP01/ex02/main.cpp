#include <iostream>
#include <string.h>

int main(){
	//string variable
	std::string s = "HI THIS IS BRAIN";
	//A pointer to variavle s
	std::string *ptr = &s;
	//A reference (alias) for s
	std::string &ref = s;

	// output result
	std::cout << "s: " << s << std::endl;
	std::cout << "ptr: " << *ptr << std::endl;
	std::cout << "ref: " << ref << std::endl;
	
	// address result
	std::cout << "s: " << &s << std::endl;
	std::cout << "ptr: " << &ptr << std::endl;
	std::cout << "ref: " << &ref << std::endl;

}
