#include "4.h"
#include <iostream>
#include <ostream>


void print_hex(int i) {
	{
		MyGuard g(std::cout);
		std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cout << i;
	}
	std::cout << std::endl << i;
}


int main()
{
	print_hex(100000);
	
	return 0;
}