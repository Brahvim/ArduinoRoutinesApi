#include <Arduino.h>
#include "RoutinesApi.hpp"
#include "BrahvimArduinoUtils.hpp"

class a : public RoutinesApi::IRoutine {

    virtual void setup() {
        Serial.println("Hello, world!");
    }

};

std::initializer_list<RoutinesApi::IRoutine*> list { new a };

void setup() {
    Serial.begin(9600);
    RoutinesApi::setup();
}

void loop() {
    RoutinesApi::loop();
}

std::initializer_list<RoutinesApi::IRoutine*> fixRoutinesList() {
    return list;
}
