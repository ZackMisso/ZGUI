#include "combinationCache.h"

CombinationCache* CombinationCache::instance = 0x0;

CombinationCache::CombinationCache() {
  cache = new Array<Array<Integer>*>();
}

CombinationCache::~CombinationCache() {
  for(int i=0;i<cache->getSize();i++)
    cache->get(i)->clear();
  while(cache->getSize())
    delete cache->removeLast();
  delete cache;
}

CombinationCache* CombinationCache::getInstance() {
  return instance;
}

void CombinationCache::initialize() {
  if(!instance)
    instance = new CombinationCache();
}

void CombinationCache::destroy() {
  if(instance)
    delete instance;
}

int CombinationCache::getCombination(int n,int r) {
  int val = -1;
  if(n < cache->getSize())
    val = findCombination(n,r);
  if(val==-1)
    return calculateCombination(n,r);
  return val;
}

int CombinationCache::findCombination(int n,int r) {
  return cache->get(n)->get(r).val;
}

int CombinationCache::calculateCombination(int n,int r) {
  bool deb = false;
  while(cache->getSize() < n+1) {
    Array<Integer>* newAry = new Array<Integer>();
    for(int i=0;i<cache->getSize()+1;i++)
      newAry->add(-1);
    cache->add(newAry);
    deb = true;
  }
  int result = factorial(n) / (factorial(r) * factorial(n-r));
  cache->get(n)->replace(r,Integer(result));
  return result;
}

int CombinationCache::factorial(int val) {
  if(val == 0)
    return 1;
  int product = 1;
  for(int i=1;i<=val;i++)
    product *= i;
  return product;
}
