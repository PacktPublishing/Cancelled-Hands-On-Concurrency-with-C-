#include <thread>
#include <iostream>

void hello( ) {
	std::cout << "Hello ";
}

int main( ) {
	std::thread t1( hello );
	t1.join( );

	std::cout << "World" << std::endl;
	return 0;
}