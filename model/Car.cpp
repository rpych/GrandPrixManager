#include "Car.hpp"
#include "Tires.hpp"

namespace gp::model
{

ACar::ACar(const std::string& engineProducer, std::shared_ptr<ATires> tires):
      engineProducer(engineProducer), tires(tires) {}

//------------

Car::Car(const std::string& engineProducer, std::shared_ptr<ATires> tires):
     ACar(engineProducer, tires) {}

}