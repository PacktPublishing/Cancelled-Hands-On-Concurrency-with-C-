// shopping-join.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

void orderCakeTask( std::string flavor ) {
	std::ostringstream r;
	r << "Friend ordered a " << flavor << " Cake!" << std::endl;
	std::cout << r.str( );
}

int main( ) {
	std::thread friend1( orderCakeTask, "Chocolate" );
	friend1.join( );
	std::cout << "I am at the register!" << std::endl;
	return 0;
}
