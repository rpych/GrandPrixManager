#pragma once
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include "GrandPrix.hpp"

namespace gp::simulator
{

class Season
{
  std::string previousGPTrackName;
  std::string careerDriverName;
  std::unique_ptr<AGrandPrix> grandPrix;
public:
  Season();
  ~Season();
  void readLastTrackName();
  void readDriversClassification();
  void writeLastTrackName();
  void writeDriversClassification();
  void updateDriversClassification();
  void setGP(std::unique_ptr<AGrandPrix> currentGrandPrix);
  void setPreviousGPTrackName(const std::string& trackName);
  const std::string& getCareerDriverName() { return careerDriverName; }
  void setCareerDriverName(const std::string driverName);
  std::shared_ptr<model::ATrack> chooseTrack();
  std::vector<std::shared_ptr<model::ADriver>>& getResults();
  void conductQualification(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions);
  void conductRace(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions,
                   std::queue<std::shared_ptr<model::APitStop>> pitStops);
};

}