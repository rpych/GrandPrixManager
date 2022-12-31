#include "ClassificationData.hpp"
#include "DriversData.hpp"
#include "../model/Driver.hpp"
#include "../utils/Constants.hpp"


namespace gp::data
{

std::map<int, int> ClassificationData::initPlaceScoring()
{
  std::map<int, int> placeScoringTemp {{1, 25}, {2, 18}, {3, 15}, {4, 12},
                                       {5, 10}, {6, 8}, {7, 6}, {8, 4},
                                       {9, 2}, {10, 1}, {11, 0}, {12, 0},
                                       {13, 0}, {14, 0}, {15, 0}, {16, 0},
                                       {17, 0}, {18, 0}, {19, 0}, {20, 0}};
  return placeScoringTemp;
}

std::map<std::string, int> ClassificationData::driversClassification {};

std::map<int, int> ClassificationData::placeScoring {initPlaceScoring()};

void ClassificationData::createInitialDriversResults()
{
  std::vector<std::string>& driversNames = DriversData::getDriversNames();
  std::for_each(driversNames.begin(), driversNames.end(), [](std::string& name)
  {
    driversClassification[name] = 0;
  });
}

void ClassificationData::readCurrentClassification()
{
  std::filesystem::path p(utils::CLASSIFICATION_FILE_PATH);
  bool fileExists = std::filesystem::exists(p);
  if (not fileExists)
  {
    createInitialDriversResults();
    return;
  }

  std::ifstream driversClassFile (utils::CLASSIFICATION_FILE_PATH);
  if (driversClassFile.is_open())
  {
    std::string line{};
    while (std::getline(driversClassFile, line))
    {
      auto delIt = line.find(";");
      std::string driverName = std::string(line.begin(), line.begin()+delIt);
      int overallPoints = std::stoi(std::string(line.begin()+delIt+1, line.end()));
      driversClassification[driverName] = overallPoints;
    }
    driversClassFile.close();
  }
}

void ClassificationData::updateDriversResults(std::vector<std::shared_ptr<model::ADriver>>& drivers)
{
  int position = 1;
  std::for_each(drivers.begin(), drivers.end(), [&position](std::shared_ptr<model::ADriver>& driver)
  {
    driversClassification[driver->getName()] += placeScoring[position]; //driversClassification[driver->getName()] + placeScoring[position];
    position++;
  });
}

void ClassificationData::saveDriversResults()
{
  std::ofstream driversClassFile (utils::CLASSIFICATION_FILE_PATH);
  if (driversClassFile.is_open())
  {
    std::for_each(driversClassification.begin(), driversClassification.end(), [&driversClassFile](auto& result)
    {
      std::string line = result.first + ";" + std::to_string(result.second) + "\n";
      driversClassFile << line;
    });
    driversClassFile.close();
  }
}

void ClassificationData::showCurrentSeasonClassification()
{
  std::vector<std::pair<std::string, int>> currentClassification;
  std::copy(driversClassification.begin(), driversClassification.end(), std::back_inserter(currentClassification));
  std::sort(currentClassification.begin(), currentClassification.end(), [](auto& e1, auto& e2)
  {
    return e1.second > e2.second;
  });

  int position = 1;
  std::for_each(currentClassification.begin(), currentClassification.end(), [&position](auto& entry)
  {
    std::cout<<position<<". "<<entry.first<<" - "<<entry.second<<std::endl;
    position++;
  });
}

}