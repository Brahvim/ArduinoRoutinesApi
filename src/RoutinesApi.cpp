#include <Arduino.h>

#include "RoutinesApi.hpp"
#include "BrahvimMacroUtils.hpp"
#include "BrahvimArduinoUtils.hpp"
#include "RoutinesApiDebugLogging.hpp"

void setup() {
    start();
}

void loop() {
}

namespace RoutinesApi {

    typedef size_t routine_t;
    typedef size_t routine_list_t;

    RoutinesApi::IRoutine::IRoutine() {
        if (RoutinesApi::createRoutine(this->id) != RoutinesApi::ApiCallResult::OK) {
        }
    }

    RoutinesApi::IRoutine::~IRoutine() {
        switch (RoutinesApi::deleteRoutine(this->id)) {
            case RoutinesApi::ApiCallResult::ROUTINE_ABSENT: {
            } break;

            default: { }
        }
    }

    routine_t createRoutine() {
    }

    routine_t deleteRoutine() { }

}
