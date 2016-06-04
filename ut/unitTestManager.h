#pragma once

enum TestResult {
  UT_PASS,
  UT_FAIL,
  UT_UNKNOWN
};

class UnitTestManager {
public:
  static TestResult runAllTests();
  static TestResult runAllMathTests();
};
