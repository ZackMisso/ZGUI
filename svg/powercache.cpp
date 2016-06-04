#include "powerCache.h"

PowerCache* PowerCache::instance = 0x0;

PowerCache::PowerCache() {
  // to be implemented
}

PowerCache::~PowerCache() {
  // to be implemented
}

PowerCache* PowerCache::getInstance() {
  return instance;
}

void PowerCache::initialize() {
  if(!instance)
    instance = new PowerCache();
}

void PowerCache::destroy() {
  if(instance)
    delete instance;
}
