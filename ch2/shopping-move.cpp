// shopping-move.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <unistd.h>

void orderCakeTask( std::string flavor ) {
	// usleep( 200 );
	std::ostringstream r;
	r << "Friend ordered a " << flavor << " Cake!" << std::endl;
	std::cout << r.str( );
}

void findItems( std::vector< std::string > items ) {
	std::ostringstream l;
	for ( auto& s : items ) {
		l << "Found: " << s << std::endl;
	}
	std::cout << l.str( );
	std::cout << "I am at the register!" << std::endl;
}

void taskManager( std::thread t1 ) {
	t1.join( );
}

int main( ) {
	std::thread friend1( orderCakeTask, "Chocolate" );
	taskManager( std::move( friend1 ) );

	std::thread friend2( findItems, std::vector< std::string >{"Soda", "Ice Cream", "Pizza"} );
	taskManager( std::move( friend2 ) );

	return 0;
}