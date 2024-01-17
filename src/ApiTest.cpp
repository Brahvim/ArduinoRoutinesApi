#include <Arduino.h>
#include "RoutinesApi.hpp"

void setup() {
    RoutinesApi::setup();
}

void loop() {
    RoutinesApi::loop();
}

std::initializer_list<RoutinesApi::IRoutine*> fixRoutinesList() {
    Serial.begin(9600);
    RoutinesApi::setup();

    return std::initializer_list<RoutinesApi::IRoutine*>{ };
}
