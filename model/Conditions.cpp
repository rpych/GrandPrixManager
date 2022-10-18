#include <random>
#include "Conditions.hpp"
#include "../utils/TrackConditions.hpp"
#include "../utils/TireType.hpp"
#include "../model/Tires.hpp"

#include <iostream>

namespace gp::model
{

AConditions::AConditions()
{}

std::map<TiresInConditions, double> AConditions::initCondTirePaceFactors()
{
  std::map<TiresInConditions, double> mapping;
  mapping[std::make_pair<>(TrackConditions::DRY, TireType::SOFT)]                = 0.3;
  mapping[std::make_pair<>(TrackConditions::DRY, TireType::MEDIUM)]              = 0.25;
  mapping[std::make_pair<>(TrackConditions::DRY, TireType::HARD)]                = 0.2;
  mapping[std::make_pair<>(TrackConditions::DRY, TireType::INTERMEDIATE)]        = -0.1;
  mapping[std::make_pair<>(TrackConditions::DRY, TireType::WET)]                 = -0.2;
  mapping[std::make_pair<>(TrackConditions::MEDIUM_WET, TireType::SOFT)]         = -0.1;
  mapping[std::make_pair<>(TrackConditions::MEDIUM_WET, TireType::MEDIUM)]       = -0.1;
  mapping[std::make_pair<>(TrackConditions::MEDIUM_WET, TireType::HARD)]         = 0.0;
  mapping[std::make_pair<>(TrackConditions::MEDIUM_WET, TireType::INTERMEDIATE)] = 0.3;
  mapping[std::make_pair<>(TrackConditions::MEDIUM_WET, TireType::WET)]          = 0.15;
  mapping[std::make_pair<>(TrackConditions::WET, TireType::SOFT)]                = -0.3;
  mapping[std::make_pair<>(TrackConditions::WET, TireType::MEDIUM)]              = -0.3;
  mapping[std::make_pair<>(TrackConditions::WET, TireType::HARD)]                = -0.2;
  mapping[std::make_pair<>(TrackConditions::WET, TireType::INTERMEDIATE)]        = 0.15;
  mapping[std::make_pair<>(TrackConditions::WET, TireType::WET)]                 = 0.3;
  return mapping;
}

std::map<TiresInConditions, double> AConditions::condTirePaceFactors{initCondTirePaceFactors()};


//-----------------------

Conditions::Conditions(): AConditions(), currentConditions(), conditionsNo(0)
{}

Conditions::Conditions(std::vector<utils::TrackConditions> conditions): AConditions(), currentConditions(conditions), conditionsNo(0)
{}

double Conditions::getCurrentCondTirePaceFactor(std::shared_ptr<model::ATires> tires)
{
  TireType tireType = tires->getTiresType();
  //std::cout<<"Conditions = "<<static_cast<int>(currentConditions.at(conditionsNo))<<std::endl;
  return condTirePaceFactors[std::make_pair<>(currentConditions.at(conditionsNo), tireType)];
}

void Conditions::setCurrentConditons()
{
  changeConditions();
}

void Conditions::changeConditions()
{
   conditionsNo++;
}

utils::TrackConditions Conditions::getCurrentTrackConditions()
{
  return currentConditions.at(conditionsNo);
}

} //gp::model
