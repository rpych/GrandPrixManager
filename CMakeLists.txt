cmake_minimum_required(VERSION 3.2)

# project name
project(grand_prix_manager)

#file(GLOB SOURCES "src/*.cpp")
# simulator/practiceSimulator/
# simulator/qualiSimulator/
add_executable(grand_prix_manager
               data/TeamsData.cpp
               data/CarsData.cpp
               data/DriversData.cpp
               data/ConditionsData.cpp
               model/Car.cpp
               model/Conditions.cpp
               model/Driver.cpp
               model/PitStop.cpp
               model/PitWall.cpp
               model/SessionInfo.cpp
               model/Team.cpp
               model/Tires.cpp
               model/Track.cpp
               simulator/GrandPrixSession.cpp
               simulator/GrandPrix.cpp
               simulator/raceSimulator/RaceSimulator.cpp
               main.cpp)

target_include_directories(grand_prix_manager
                           PRIVATE
                           ${PROJECT_SOURCE_DIR}/data
                           ${PROJECT_SOURCE_DIR}/model
                           ${PROJECT_SOURCE_DIR}/utils
                           ${PROJECT_SOURCE_DIR}/simulator
                           ${PROJECT_SOURCE_DIR}/simulator/raceSimulator
                           ${PROJECT_SOURCE_DIR}/simulator/qualiSimulator
                           ${PROJECT_SOURCE_DIR}/simulator/practiceSimulator)

