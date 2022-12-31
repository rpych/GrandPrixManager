#include <iostream>
#include <algorithm>
#include "Viewer.hpp"
#include "../model/Conditions.hpp"
#include "../model/Driver.hpp"
#include "../data/ConditionsData.hpp"
#include "../data/TracksData.hpp"
#include "../data/ClassificationData.hpp"
#include "../model/PitStop.hpp"
#include "../model/Tires.hpp"
#include "../utils/Constants.hpp"

namespace gp::viewer
{

Viewer::Viewer(): gpSeason(std::make_unique<simulator::Season>())
{}

void Viewer::showConditions(utils::TrackConditions conditions)
{
  switch (conditions)
  {
    case TrackConditions::DRY:
      std::cout<<"DRY"<<std::endl;
      break;
    case TrackConditions::MEDIUM_WET:
      std::cout<<"MEDIUM_WET"<<std::endl;
      break;
    case TrackConditions::WET:
      std::cout<<"WET"<<std::endl;
      break;
    default:
      break;
  }
}

TireType Viewer::transformInputToTireType(const std::string& tireType)
{
  std::map<std::string, utils::TireType> tiresMapping {{"s", TireType::SOFT}, {"m", TireType::MEDIUM},
                                                       {"h", TireType::HARD}, {"i", TireType::INTERMEDIATE},
                                                       {"w", TireType::WET}};
  try
  {
    return tiresMapping.at(tireType);
  }
  catch(std::out_of_range e)
  {
    return TireType::SOFT;
  }
}

void Viewer::showLapsWhenConditionsWillChange(std::shared_ptr<model::ATrack> track)
{
  std::cout<<"First conditions change on lap "<<static_cast<int>(utils::COND_DURATION_COEF * track->getLaps())<<std::endl;
  std::cout<<"Second conditions change on lap "<<static_cast<int>(2 * utils::COND_DURATION_COEF * track->getLaps())<<std::endl;
}

void Viewer::setCareerDriver()
{
  std::string driverName;
  std::cout<<"Enter driver name to choose career"<<std::endl;
  std::getline(std::cin, driverName);
  gpSeason->setCareerDriverName(driverName);
}

void Viewer::showCurrentSeasonClassification()
{
  data::ClassificationData::showCurrentSeasonClassification();
}

void Viewer::run()
{
  setCareerDriver();
  std::cout<<"RUN "<<data::TracksData::getTracksNum()<<" GPs"<<std::endl;
  for (int i = 0; i < data::TracksData::getTracksNum(); ++i)
  {
    runSingleGP();
  }
  std::cout<<"Whole season simulated"<<std::endl;
}

void Viewer::runSingleGP()
{
  std::shared_ptr<model::ATrack> currentTrack = gpSeason->chooseTrack();
 
  std::cout<<"### New Grand Prix starts ###"<<std::endl;
  std::cout<<"Current track is "<<currentTrack->getName()<<" with "<<currentTrack->getLaps()<<" laps"<<std::endl;
  std::unique_ptr<model::AConditions> qualiConditions = std::make_unique<model::Conditions>(data::ConditionsData::getConditions());
  std::cout<<"Qualification conditions: "<<std::endl;
  showConditions(qualiConditions->getCurrentTrackConditions());
  gpSeason->conductQualification(currentTrack, std::move(qualiConditions));
  std::cout<<"-----QUALIFICATION RESULTS-----"<<std::endl;
  showGPSessionResults();

  std::vector<utils::TrackConditions>& raceConditionTypes = data::ConditionsData::getConditions();
  std::unique_ptr<model::AConditions> raceConditions = std::make_unique<model::Conditions>(raceConditionTypes);
  std::cout<<"\nRace conditions: "<<std::endl;
  showLapsWhenConditionsWillChange(currentTrack);
  for (int i = 0; i < raceConditionTypes.size(); ++i)
  {
    showConditions(raceConditionTypes.at(i));
  }
  
  std::queue<std::shared_ptr<model::APitStop>> pitStops = planStrategy();
  gpSeason->conductRace(currentTrack, std::move(raceConditions), pitStops);
  std::cout<<"-----RACE RESULTS-----"<<std::endl;
  showGPSessionResults();
  gpSeason->updateDriversClassification();
  std::cout<<"Grand Prix finished"<<std::endl;
  std::cout<<"Current championship classification:"<<std::endl;
  showCurrentSeasonClassification();
}

void Viewer::showGPSessionResults()
{
  int position = 1;
  std::vector<std::shared_ptr<model::ADriver>>& drivers = gpSeason->getResults();
  std::for_each(drivers.begin(), drivers.end(), [&position](auto& driver)
  {
    std::cout<<"Position "<<position<<" - "<<driver->getName()<<", score = "<<driver->getSessionScore()<<std::endl;
    position++;
  });
}

std::queue<std::shared_ptr<model::APitStop>> Viewer::planStrategy()
{
  std::queue<std::shared_ptr<model::APitStop>> pitStops;
  std::string lap{};
  std::string tireType{};
  while (true)
  {
    std::cout<<"To quit from strategy settings insert 'q'...";
    std::cout<<"\nInsert lap number to make pit stop"<<std::endl;
    std::getline(std::cin, lap);
    if (lap == "q")
    {
      break;
    }
    std::cout<<"Choose tire type: soft:s ; medium:m ; hard:h ; intermediate:i ; wet:w"<<std::endl;
    std::getline(std::cin, tireType);
    if (tireType == "q")
    {
      break;
    }
    TireType tires = transformInputToTireType(tireType);
    pitStops.push(std::make_shared<model::PitStop>(std::stoi(lap), std::make_shared<model::Tires>(0, tires)));
    std::cout<<"New tires set added: ("<<lap<<", "<<tireType<<")"<<std::endl;
  }
  return pitStops;
}

}