#include <Arduino.h>
#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"

void setup() {
    start();
}

void loop() {
}

namespace RoutinesApi {

    // typedef size_t routine_t;
    // typedef size_t routine_list_t;

    RoutineManager::RoutineManager(const std::initializer_list<RoutinesApi::IRoutine*> &p_routinesList) {
        // BrahvimArduinoUtils::AvrOnly::arduinoSleep(); // Not needed - references cannot be null!
        this->routines = p_routinesList;
    }

    RoutinesApi::ApiCallResult RoutineManager::enableRoutine() {

    }

    RoutinesApi::ApiCallResult RoutineManager::disableRoutine() {

    }

    bool RoutineManager::hasRoutine(RoutinesApi::IRoutine &routine) {
        // for (RoutinesApi::IRoutine *i; i != )
    }

    bool RoutineManager::isRoutineEnabled(RoutinesApi::IRoutine &routine) {

    }

}
