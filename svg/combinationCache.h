#pragma once

#include "../dataStructures/array.h"
#include "../dataStructures/integer.h"

class CombinationCache {
private:
  static CombinationCache* instance;
  CombinationCache();
  int calculateCombination(int n,int r);
  int findCombination(int n,int r);
  int factorial(int val);
  Array<Array<Integer>*>* cache;
  Array<Integer>* factorialCache;
public:
  ~CombinationCache();
  static CombinationCache* getInstance();
  static void initialize();
  static void destroy();
  int getCombination(int n,int r);
};
