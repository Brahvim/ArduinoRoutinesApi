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
    Serial.println("`start()` ended!");
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

#pragma region // `static` stuff!
    // `void(*)` is the same as `void(*)()` and `void(*)(void)`!
    // I choose the lattermost since it is the most declarative/cleaner.

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
#pragma endregion

#pragma region // `IRoutine` things!
    IRoutine::IRoutine() {
        const RoutinesApi::ApiCallResult result = RoutinesApi::createRoutine(this->id);
        if (result == RoutinesApi::ApiCallResult::OK)
            return;

        DEBUG_PRINT("Failed to instantiate an `IRoutine` instance! Reason:");
        switch (result) {
            case RoutinesApi::ApiCallResult::MALLOC_FAILURE: {
                DEBUG_PRINT("`malloc()` failed!");
            } break;

            default: { }
        }
    }

    IRoutine::~IRoutine() {
        switch (RoutinesApi::deleteRoutine(this->id)) {
            case RoutinesApi::ApiCallResult::ROUTINE_ABSENT: {
            } break;

            default: { }
        }
    }
#pragma endregion

#pragma region // Data-oriented API functions for routines!
    RoutinesApi::ApiCallResult createRoutine(routine_t &p_routineId) {

    }

    RoutinesApi::ApiCallResult deleteRoutine(routine_t &p_routineId) {
    }

    RoutinesApi::ApiCallResult addRoutineExit(routine_t &id, void(*fxnPtr)(void)) {
        sizeof(id);
        sizeof(fxnPtr);
    }

    RoutinesApi::ApiCallResult addRoutineMethods(routine_t &id, RoutinesApi::IRoutine &itfImpl) {
        return RoutinesApi::ApiCallResult::OK;
    }
#pragma endregion

#pragma region // Data-oriented API functions for lists of routines!
    bool isRoutineList(const routine_t p_routineListId) {
        for (auto i : s_routineListsToRoutineVectorsMap)
            if (i.first == p_routineListId)
                return true;

        return false;
    }
#pragma endregion

}
