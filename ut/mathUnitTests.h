#pragma once

#include "unitTestManager.h"

class MathUnitTests {
public:
  static TestResult runAllTests();
  static TestResult runCombinationTests();
  static TestResult runFactorialTests();
  static TestResult runCacheTests();
};
