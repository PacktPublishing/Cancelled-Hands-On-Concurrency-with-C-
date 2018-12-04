#include <thread>
#include <iostream>
#include <vector>

void concurrentThread( ) {
	std::cout << "Hello concurrent thread " << std::this_thread::get_id( ) << std::endl;
}

int main( ) {
	std::vector< std::thread > threads;

	for ( int i = 0; i < 5; ++i ) {
		threads.push_back( std::thread( concurrentThread ) );
	}

	for ( auto& thread : threads ) {
		thread.join( );
	}

	return 0;
}