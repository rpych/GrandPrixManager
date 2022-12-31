#include "GrandPrix.hpp"
#include "Season.hpp"
#include "../model/Track.hpp"
#include "../data/TracksData.hpp"
#include "../model/Conditions.hpp"
#include "../data/ClassificationData.hpp"

namespace gp::simulator
{

Season::Season(): grandPrix(std::make_unique<GrandPrix>())
{
  readLastTrackName();
  readDriversClassification();
}

Season::~Season()
{
  writeLastTrackName();
  writeDriversClassification();
}

void Season::readLastTrackName()
{
  std::ifstream lastTrackFile ("../storage/lastGP.txt");
  std::string trackName;
  if (lastTrackFile.is_open())
  {
    lastTrackFile >> trackName;
  }
  setPreviousGPTrackName(trackName);
  lastTrackFile.close();
}

void Season::readDriversClassification()
{
  data::ClassificationData::readCurrentClassification();
}

void Season::writeLastTrackName()
{
  std::ofstream lastTrackFile ("../storage/lastGP.txt");
  if (lastTrackFile.is_open())
  {
    lastTrackFile << previousGPTrackName;
  }
  lastTrackFile.close();
}

void Season::writeDriversClassification()
{
  data::ClassificationData::saveDriversResults();
}

void Season::updateDriversClassification()
{
  data::ClassificationData::updateDriversResults(getResults());
}

void Season::setGP(std::unique_ptr<AGrandPrix> currentGrandPrix)
{
  grandPrix = std::move(currentGrandPrix);
}

void Season::setPreviousGPTrackName(const std::string& trackName)
{
  previousGPTrackName = trackName;
}

void Season::setCareerDriverName(const std::string driverName)
{
  careerDriverName = driverName;
}

std::shared_ptr<model::ATrack> Season::chooseTrack()
{
  std::shared_ptr<model::ATrack> track = data::TracksData::getNextTrack(previousGPTrackName);
  setPreviousGPTrackName((track) ? track->getName() : "");
  return track;
}

std::vector<std::shared_ptr<model::ADriver>>& Season::getResults()
{
  return grandPrix->getSessionResults();
}

void Season::conductQualification(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions)
{
  grandPrix->prepareQualiSession(track, std::move(conditions));
  grandPrix->conductSession();
}

void Season::conductRace(std::shared_ptr<model::ATrack> track, std::unique_ptr<model::AConditions> conditions,
                         std::queue<std::shared_ptr<model::APitStop>> pitStops)
{
  grandPrix->prepareRaceSession(track, std::move(conditions));
  grandPrix->setStrategyForDriver(careerDriverName, pitStops);
  grandPrix->conductSession();
}

}