#include "PitStop.hpp"
#include "../utils/TireType.hpp"

namespace gp::model
{

APitStop::APitStop(int lap, std::shared_ptr<ATires> tires): lap(lap), tires(tires)
{}

//
PitStop::PitStop(int lap, std::shared_ptr<ATires> tires): APitStop(lap, tires) 
{}



}