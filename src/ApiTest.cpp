#include <Arduino.h>
#include "RoutinesApi.hpp"
#include "RoutinesApiDebugLogging.hpp"

void start() {
    Serial.begin(9600);

    RoutinesApi::routine_t routineId = 42;
    class : public RoutinesApi::IRoutine {
        void setup() override { Serial.println("Setting up routine..."); }
        void loop() override { Serial.println("Running routine..."); }
        void out() override { Serial.println("Routine switching out..."); }
    } testRoutine;

    RoutinesApi::ApiCallResult result = RoutinesApi::addRoutineMethods(routineId, testRoutine);
}
