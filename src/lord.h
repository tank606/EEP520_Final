

#include "enviro.h"
#include <iostream>
#include <math.h>

namespace {
    using namespace enviro;
    using namespace std;

    // Let the lord go straight
    class MovingForward : public State, public AgentInterface {
        public:
        void entry(const Event& e) {}
        void during() {
            track_velocity(1,0);
            if (sensor_value(0) < 3) { //When approaching the target, issue an event
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        void set_tin_name(std::string s) {tick_name = s;}
        string tick_name;
    };

    // Set stop state, once event is thrown, enter new state, stop motion and label
    class Stop : public State, public AgentInterface {
        public:
        void entry(const Event& e) {}
        void during() {
            emit(Event("fail"));
            track_velocity(0,0);
            label(s, -20, -20);
        }
        void exit(const Event& e) {}
        std::string s = "Game over";
    };

    // The LordController class simply defines the states and transitions of
    // the state machine
    class LordController : public StateMachine, public AgentInterface {
        public:
        LordController() : StateMachine () {
            set_initial(move_forward);
            tick_name = "tin_" + std::to_string(rand()%1000);
            add_transition(tick_name, move_forward, stop);
            move_forward.set_tin_name(tick_name);
        }

        MovingForward move_forward;
        Stop stop;
        string tick_name;
    };

    class Lord : public Agent {
        public:
        Lord(json spec, World& world) : Agent(spec, world) {
            add_process(c);
        }

        LordController c;
    };
    
    DECLARE_INTERFACE(Lord)
}
