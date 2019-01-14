#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

void orderCakeTask( std::string flavor ) {
  std::ostringstream r;
  usleep( 5000 );
  r << "Friend ordered a " << flavor << " Cake!" << std::endl;
  std::cout << r.str( );
}

int main( ) {
  std::thread friend1( orderCakeTask, "Chocolate" );
  usleep( 6000 );
  std::cout << "I am at the register!" << std::endl;
  friend1.join( );
  return 0;
}
