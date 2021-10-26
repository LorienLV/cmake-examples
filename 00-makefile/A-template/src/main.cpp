#include <iostream>
#include <cmath>

#ifndef VALUE
   #define VALUE 0
#endif

int main(int argc, char *argv[]) {
   std::cout << "VALUE = " << VALUE << " " << sqrt((double)VALUE) << std::endl;

   return EXIT_SUCCESS;
}
