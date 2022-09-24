#pragma once
#include <string>

namespace gp::utils
{
  enum class TireType;
}
using namespace gp::utils;

namespace gp::model
{

class ATires
{
  int lapsAge;
  TireType type;
public:
  ATires(int lapsAge, TireType type);
};

class Tires: public ATires
{
public:
  Tires();
  Tires(int lapsAge, TireType type);
};
} //gp::model