#pragma once
#include <map>
#include <string>
#include <memory>

namespace gp::utils
{
  enum class TireType;
}
using namespace gp::utils;

namespace gp::model
{

class ATires
{
protected:
  int lapsAge;
  TireType type;
  static std::map<TireType, double> tireUsagePaceFactors;

  static std::map<TireType, double> initTireUsagePaceFactors();
public:
  ATires(int lapsAge, TireType type);
  virtual ~ATires() {}
  int getTiresAge() { return lapsAge; }
  TireType getTiresType() { return type; }
  virtual double getTiresAgeFactor() = 0;
  virtual void updateTiresAge() = 0;
};

class Tires: public ATires
{
public:
  Tires();
  Tires(int lapsAge, TireType type);
  Tires(std::shared_ptr<ATires> tires);
  virtual ~Tires() {}
  virtual double getTiresAgeFactor() override;
  virtual void updateTiresAge() override;
};
} //gp::model