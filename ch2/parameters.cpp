#include <thread>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> greetings {"Hola", "Gutentag", "Bonure", "Konnichiwa"};
std::vector<std::string> worlds {"Mundo", "Welt", "Monde", "Sekai" };

void hello( std::vector<std::string> greet, std::string var) {
    for (auto g : greet) {
	    std::cout << g << " " << var << std::endl;
    }
}

int main( ) {
	std::thread t1( hello, greetings, "World with Parameters" );
	t1.join( );
	return 0;
}