#include <iostream>
#include <string>
#include "range.h"


int main(){

	range range2("(-1,1)");
	range range("[1,3]");
	std::cout << range.isNotEqual(range2.ran) << std::endl;
	
	

	
	return 0;
}
