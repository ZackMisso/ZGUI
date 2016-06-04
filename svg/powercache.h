#pragma once

class PowerCache {
private:
  static PowerCache* instance;
  PowerCache();
public:
  ~PowerCache();
  // class methods
  static PowerCache* getInstance();
  static void initialize();
  static void destroy();
};
