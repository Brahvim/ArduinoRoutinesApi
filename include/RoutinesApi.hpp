#ifndef ROUTINES_API_NO_CUSTOM_SETUP
/** @brief Please use this instead of Arduino's `setup()`. `RoutinesApi` handles `loop()`. */
void start();
#endif

namespace RoutinesApi {

    /** @brief Error states for `RoutinesApi`. */
    enum class ApiCallResult {

        /** @brief My API uses `malloc()` because exceptions don't exist. CHECK FOR THIS! */
        MALLOC_FAILURE,

        /** @brief No such `RoutinesManager::Routine` object was registered! */
        ROUTINE_ABSENT,

        /** @brief Everything went fine, have a good day! */
        OK,

    };

    /** @brief Routines' handle/ID! "Holds routines"! */
    typedef size_t routine_t;

    /** @brief Routine @e lists' handle/ID! "Holds routine lists"! */
    typedef size_t routine_list_t;

    const char* describeError(const RoutinesApi::ApiCallResult error);

    /** @brief Abstract class representing a routine object. Love for the C++ guys, brothers and sisters! */
    struct IRoutine {

        IRoutine();

        /** Called when the sketch starts. */
        virtual void setup() = 0;

        /** Called according to how your `RoutineManager` is configured. */
        virtual void loop() = 0;

        /** Called when the `RoutineManager` has been switched. */
        virtual void out() = 0;

        virtual ~IRoutine();

    private:

        routine_t id;

    };

#pragma region // Routines API!
    bool doesRoutineExist(const routine_t id);
    RoutinesApi::ApiCallResult createRoutine(routine_t &id);
    RoutinesApi::ApiCallResult deleteRoutine(routine_t &id);

    // Function pointers take `24` bytes!
    // Storing calls to them in lambdas and call those lambdas in `IRoutine`s?
    // Nope! Even worse idea. Like, `48` bytes or something!
    // We better *suffer* from dynamic dispatch and decrease memory and lookups
    // by using our *just `12` bytes large[!]* `IRoutine`s! Wooooooo-hoo!
    // RoutinesApi::ApiCallResult addRoutineLoop(routine_t &id, void(*fxnPtr)(void));
    // RoutinesApi::ApiCallResult addRoutineExit(routine_t &id, void(*fxnPtr)(void));
    // RoutinesApi::ApiCallResult addRoutineSetup(routine_t &id, void(*fxnPtr)(void));
    RoutinesApi::ApiCallResult addRoutineMethods(routine_t &id, const RoutinesApi::IRoutine &itfImpl);
#pragma endregion

#pragma region // Routine-lists API!
    bool doesRoutineListExist(const routine_list_t listId, const routine_t routineId);
    bool doesRoutineListInclude(const routine_list_t listId, const routine_t routineId);

    RoutinesApi::ApiCallResult createRoutineList(routine_list_t &id);
    RoutinesApi::ApiCallResult deleteRoutineList(routine_list_t &id);

    RoutinesApi::ApiCallResult addRoutineToList(const routine_list_t listId, const routine_t routineId);
    RoutinesApi::ApiCallResult removeRoutineFromList(const routine_list_t listId, const routine_t routineId);

    RoutinesApi::ApiCallResult toggleRoutineInList(const routine_list_t listId, const routine_t routineId);
    RoutinesApi::ApiCallResult enableRoutineInList(const routine_list_t listId, const routine_t routineId);
    RoutinesApi::ApiCallResult disableRoutineInList(const routine_list_t listId, const routine_t routineId);

    RoutinesApi::ApiCallResult isRoutineEnabledForList(const routine_list_t listId, const routine_t routineId);
    RoutinesApi::ApiCallResult isRoutineEnabledAndInList(const routine_list_t listId, const routine_t routineId);

#pragma endregion

}
