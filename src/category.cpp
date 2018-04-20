#ifndef CATEGORY_CPP
#define CATEGORY_CPP

namespace Category {
  enum Type {
    None = 0,
    Scene = 1 << 0,
    Hero = 1 << 1,
    Enemy = 1 << 2,
  };
}
#endif
