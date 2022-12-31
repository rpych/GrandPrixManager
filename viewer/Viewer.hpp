#pragma once
#include <memory>
#include <queue>
#include "../model/Track.hpp"
#include "../simulator/Season.hpp"
#include "../utils/TireType.hpp"
#include "../utils/TrackConditions.hpp"


namespace gp::viewer
{

class Viewer
{
  std::unique_ptr<simulator::Season> gpSeason;
  void showConditions(utils::TrackConditions conditions);
  void setCareerDriver();
  void showLapsWhenConditionsWillChange(std::shared_ptr<model::ATrack> track);
  utils::TireType transformInputToTireType(const std::string& tireType);
  void runSingleGP();
  void showGPSessionResults();
  std::queue<std::shared_ptr<model::APitStop>> planStrategy();
  void showCurrentSeasonClassification();
public:
  Viewer();
  void run();
};

}