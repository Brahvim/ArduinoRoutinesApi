#include <initializer_list>
#include <map>

void start();

namespace RoutinesApi {

    struct IRoutine {

        /** Called when the sketch starts. */
        virtual void setup() = 0;

        /** Called according to how your `RoutineManager` is configured. */
        virtual void loop() = 0;

        /** Called when the `RoutineManager` has been switched. */
        virtual void out() = 0;

        virtual ~IRoutine() = default;

    };

    enum class ApiCallResult {

        /* No such `RoutinesManager::Routine` object was registered! */
        ROUTINE_ABSENT,

        /* Everything went fine, have a good day! */
        OK,

    };

    struct RoutineManager {

        RoutineManager(const std::initializer_list<RoutinesApi::IRoutine*> &routinesList);

        RoutinesApi::ApiCallResult enableRoutine();
        RoutinesApi::ApiCallResult disableRoutine();
        bool hasRoutine(RoutinesApi::IRoutine &routine);
        bool isRoutineEnabled(RoutinesApi::IRoutine &routine);

    private:
        std::initializer_list<RoutinesApi::IRoutine*> routines;
        const std::map<IRoutine*, int> routinesMap;
    };

}
