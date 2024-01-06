/** @brief Please use this instead of Arduino's `setup()`. `RoutinesApi` handles `loop()`. */
void start();

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

    typedef size_t routine_t;
    typedef size_t routine_list_t;

    RoutinesApi::ApiCallResult createRoutine(routine_t &id);
    RoutinesApi::ApiCallResult deleteRoutine(routine_t &id);

    RoutinesApi::ApiCallResult createRoutineList(routine_list_t &id);
    RoutinesApi::ApiCallResult deleteRoutineList(routine_list_t &id);

    /** @brief Abstract class representing a routine object. Love for the C++ guys! */
    struct IRoutine {

        IRoutine();

        /** Called when the sketch starts. */
        virtual void setup() = 0;

        /** Called according to how your `RoutineManager` is configured. */
        virtual void loop() = 0;

        /** Called when the `RoutineManager` has been switched. */
        virtual void out() = 0;

        virtual ~IRoutine();

        // ...Funny nightmares:
        // virtual routine_t getId() const final {
        //     return this->id;
        // }

    private:

        routine_t id;

    };

}
