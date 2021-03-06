// multi-sstream.cpp
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

void concurrentThread( ) {
	std::ostringstream r;
	r << "Hello concurrent thread: " << std::this_thread::get_id( ) << std::endl;
	std::cout << r.str( );
}

int main( ) {
	std::vector< std::thread > threads;

	for ( int i = 0; i < 5; ++i ) {
		// threads.push_back( std::thread( concurrentThread ) );
		threads.emplace_back( concurrentThread );
	}

	for ( auto& thread : threads ) {
		thread.join( );
	}

	return 0;
}