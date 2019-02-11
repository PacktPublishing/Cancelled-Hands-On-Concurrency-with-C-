// thread-id-example.cpp
#include <iostream>
#include <thread>

std::thread::id parentThreadId = std::this_thread::get_id( );

void isParentThread( ) {
	if ( parentThreadId == std::this_thread::get_id( ) )
		std::cout << "This is the parent process.\n";
	else
		std::cout << "This is a new thread.\n";
}

int main( ) {
	isParentThread( );
	std::thread thread( isParentThread );
	thread.join( );
}