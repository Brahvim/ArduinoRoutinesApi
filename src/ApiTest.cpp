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

RoutinesApi::FixedSizeRoutinesList fixRoutinesList() {
    class a : public RoutinesApi::IRoutine {

        virtual void setup() {
            Serial.println("Hello, world!");
        }

    };

    static RoutinesApi::FixedSizeRoutinesList list({ new a });
    return list;
}
