#include "Tires.hpp"
#include "../utils/TireType.hpp"

namespace gp::model
{

ATires::ATires(int lapsAge, TireType type): lapsAge(lapsAge), type(type) {}

std::map<TireType, double> ATires::initTireUsagePaceFactors()
{
  std::map<TireType, double> tirePaceMapping;
  tirePaceMapping[TireType::SOFT]         = -0.02;
  tirePaceMapping[TireType::MEDIUM]       = -0.012;
  tirePaceMapping[TireType::HARD]         = -0.008;
  tirePaceMapping[TireType::INTERMEDIATE] = -0.015;
  tirePaceMapping[TireType::WET]          = -0.015;
  return tirePaceMapping;
}

std::map<TireType, double> ATires::tireUsagePaceFactors{initTireUsagePaceFactors()};

//------------------
Tires::Tires():
       ATires(0, TireType::SOFT) {}

Tires::Tires(int lapsAge, TireType type):
       ATires(lapsAge, type) {}

Tires::Tires(std::shared_ptr<ATires> tires) : Tires(tires->getTiresAge(), tires->getTiresType()) {}

double Tires::getTiresAgeFactor()
{
  return tireUsagePaceFactors[type] * lapsAge;
}

void Tires::updateTiresAge()
{
  lapsAge++;
}

}