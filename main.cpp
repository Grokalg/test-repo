#include <vector>
#include <functional>
#include <iostream>

//#include "tests.h"
#include "Candle.h"

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

bool testBodyContains_PriceInsideBodyGreenCandle_ReturnsTrue()
{
    Candle candle_green{ 10.0, 3.0, 20.0, 20.0 };

    return candle_green.body_contains(15) == true;
}

bool testBodyContains_PriceInsideBodyRedCandle_ReturnsTrue()
{
    Candle candle_red{ 20.0, 3.0, 20.0, 10.0 };

    return candle_red.body_contains(15) == true;
}

bool testBodyContains_PriceOutsideBody_ReturnsFalse()
{
    Candle candle_green{ 10.0, 3.0, 20.0, 20.0 };

    return candle_green.body_contains(21) == false;
}


void initTests()
{
    tests.push_back(testBodyContains_PriceInsideBodyGreenCandle_ReturnsTrue);
    tests.push_back(testBodyContains_PriceInsideBodyRedCandle_ReturnsTrue);
    tests.push_back(testBodyContains_PriceOutsideBody_ReturnsFalse);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto& test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}
