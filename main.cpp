#define CATCH_CONFIG_MAIN
#include "catch2/catch2.hpp"
#include "catch2/tap.hpp"

unsigned int Factorial( unsigned int number ) {
  return number <= 1 ? number : Factorial(number - 1) * number;
} // Factorial

SCENARIO("Factorial test 1", "[R-1] [T-1]") {
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
}
SCENARIO("Factorial test 2", "[R-1] [T-2]") {
  REQUIRE( Factorial(0) == 1 );
  REQUIRE( Factorial(10) == 3628800 );
}
SCENARIO("Factorial test 3", "[R-1] [T-3]") {
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

SCENARIO("Factorial test 4", "[R-34] [T-1239]") {
  REQUIRE( Factorial(0) == 1 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}
SCENARIO("Factorial test 5", "[R-34] [T-456]") {
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}