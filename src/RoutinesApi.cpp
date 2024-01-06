#include <Arduino.h>

#include <map>
#include <vector>

#include "MacroUtils.hpp"
#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"
#include "RoutinesApiDebugLogging.hpp"

#pragma region // Arduino `setup()`/`loop()` internalization code.
// Extra definitions:
namespace RoutinesApi {

    void setup();

    void loop();

}

#ifndef ROUTINES_API_NO_CUSTOM_SETUP
void setup() {
    start();
    RoutinesApi::setup();
}
#endif

#ifndef ROUTINES_API_NO_CUSTOM_LOOP
void loop() {
    RoutinesApi::loop();
}
#endif
#pragma endregion

namespace RoutinesApi {

    static routine_list_t s_currentRoutineList;
    static std::map<routine_t, void(*)(void)> s_routinesLoopFxnMap;
    static std::map<routine_list_t, std::vector<routine_t>> s_routineListsToRoutineVectorsMap;

    RoutinesApi::ApiCallResult setCurrentRoutineList(const routine_list_t p_currentRoutineList) {

        return RoutinesApi::ApiCallResult::OK;

        s_currentRoutineList = p_currentRoutineList;
        return RoutinesApi::ApiCallResult::OK;
    }

    void setup() {
    }

    void loop() {
    }

    IRoutine::IRoutine() {
        if (RoutinesApi::createRoutine(this->id) != RoutinesApi::ApiCallResult::OK) {
        }
    }

    IRoutine::~IRoutine() {
        switch (RoutinesApi::deleteRoutine(this->id)) {
            case RoutinesApi::ApiCallResult::ROUTINE_ABSENT: {
            } break;

            default: { }
        }
    }

    RoutinesApi::ApiCallResult createRoutine(routine_t &p_routineId) {

    }


    RoutinesApi::ApiCallResult deleteRoutine(routine_t &p_routineId) {

    }

    bool isRoutineList(const routine_t p_routineListId) {
        for (auto i : s_routineListsToRoutineVectorsMap)
            if (i.first == p_routineListId)
                return true;

        return false;
    }

}
