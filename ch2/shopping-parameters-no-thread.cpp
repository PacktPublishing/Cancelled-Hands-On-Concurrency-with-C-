// shopping-parameters-no-thread.cpp
#include <iostream>
#include <string>
#include <thread>

void orderCakeTask( std::string flavor ) {
	std::cout << "Friend ordered a " << flavor << " Cake!" << std::endl;
}

int main( ) {
	// std::thread friend1( orderCakeTask, "Chocolate" );
	// friend1.detach( );
	orderCakeTask( "Chocolate" );
	std::cout << "I am at the register!" << std::endl;
	return 0;
}
