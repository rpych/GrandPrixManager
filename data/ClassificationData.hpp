#pragma once
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <filesystem>
#include <iostream>

namespace gp::model
{
  class ADriver;
}

namespace gp::data
{

class ClassificationData
{
private:
  static void createInitialDriversResults();
  static std::map<int, int> initPlaceScoring();
  static std::map<std::string, int> driversClassification;
  static std::map<int, int> placeScoring;
public: 
  ClassificationData() = delete;
  static std::map<std::string, int> getClassification() { std::cout<<"Size = "<<driversClassification.size()<<std::endl; return driversClassification; }
  static void readCurrentClassification();
  static void updateDriversResults(std::vector<std::shared_ptr<model::ADriver>>& drivers);
  static void saveDriversResults();
  static void showCurrentSeasonClassification();
};

};