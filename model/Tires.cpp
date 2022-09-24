#include "Tires.hpp"
#include "../utils/TireType.hpp"

namespace gp::model
{

ATires::ATires(int lapsAge, TireType type): lapsAge(lapsAge), type(type) {}

//------------------
Tires::Tires():
       ATires(0, TireType::SOFT) {}

Tires::Tires(int lapsAge, TireType type):
       ATires(lapsAge, type) {}

}