// shopping-join-id.cpp
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

std::thread::id parentThreadId = std::this_thread::get_id( );

void isParentThread( ) {
	if ( parentThreadId == std::this_thread::get_id( ) )
		std::cout << "This is the parent process.\n";
	else
		std::cout << "This is a new thread.\n";
}

void orderCakeTask( std::string flavor ) {
	isParentThread( );
	std::ostringstream r;
	usleep( 5000 );
	r << "Friend ordered a " << flavor << " Cake!" << std::endl;
	std::cout << r.str( );
}

int main( ) {
	std::thread friend1( orderCakeTask, "Chocolate" );
	usleep( 6000 );
	isParentThread( );
	std::cout << "I am at the register!" << std::endl;
	friend1.join( );
	return 0;
}
