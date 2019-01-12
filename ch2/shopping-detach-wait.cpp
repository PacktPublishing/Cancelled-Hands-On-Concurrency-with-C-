#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

void orderCakeTask( std::string flavor ) {
  std::ostringstream r;
  r << "Ordered a " << flavor << " Cake!" << std::endl;
  // usleep( 6000 );
  std::cout << r.str( );
}

int main( ) {
  std::thread friend1( orderCakeTask, "Chocolate" );
  friend1.detach( );
  usleep( 5000 );
  std::cout << "I am at the register!" << std::endl;
  return 0;
}
