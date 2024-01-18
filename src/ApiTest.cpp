#include <Arduino.h>

#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"

void setup() {
    Serial.begin(9600);
    RoutinesApi::setup();
}

void loop() {
    RoutinesApi::loop();
}

class TestRoutine : public RoutinesApi::IRoutine {

    void setup() override {
        Serial.println("Hello, world!");
    }

};

RoutinesApi::FixedSizeRoutinesList supplyRoutines() {
    static RoutinesApi::FixedSizeRoutinesList list({ new TestRoutine });
    return list;
}
