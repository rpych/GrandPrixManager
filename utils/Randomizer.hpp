#pragma once
#include <random>

namespace gp::utils
{
class Randomizer
{
  Randomizer() = delete;
public:
  static int random(int start, int end)
  {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, end-1);
    return dist(rng);
  }
};

} //gp::utils