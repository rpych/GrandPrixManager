#pragma once
#include <string>
#include <memory>


namespace gp::model
{
class ATires;

class ACar
{
  const std::string engineProducer;
  std::shared_ptr<ATires> tires;
public:
  ACar(const std::string& engineProducer, std::shared_ptr<ATires> tires);
};

class Car: public ACar
{
public:
  Car(const std::string& engineProducer, std::shared_ptr<ATires> tires);
};
} //gp::model