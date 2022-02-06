#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){

  REQUIRE(true);
  
}

TEST_CASE("fancyPower positive even test", "fancyPower"){

  REQUIRE(fancyPower(2,2) == 4);
  REQUIRE(fancyPower(6,4) == 4096);
  REQUIRE(fancyPower(16,3) == 43046721);
  REQUIRE(fancyPower(4,4) == 256);
  
}

TEST_CASE("fancyPower positive odd test", "fancyPower"){

  REQUIRE(fancyPower(3,3) == 27);
  REQUIRE(fancyPower(5,30) == 24300000);
  REQUIRE(fancyPower(7,6) == 279936);
  REQUIRE(fancyPower(3,325) == 34328125);
  
}

TEST_CASE("fancyPower negative even test", "fancyPower"){

  REQUIRE(fancyPower(2,-2) == 4);
  REQUIRE(fancyPower(6,-4) == 4096);
  REQUIRE(fancyPower(16,-3) == 43046721);
  REQUIRE(fancyPower(4,-4) == 256);
  
}

TEST_CASE("fancyPower negative odd test", "fancyPower"){

  REQUIRE(fancyPower(3,-3) == -27);
  REQUIRE(fancyPower(5,-30) == -24300000);
  REQUIRE(fancyPower(7,-6) == -279936);
  REQUIRE(fancyPower(3,-325) == -34328125);
  
}