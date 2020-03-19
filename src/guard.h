#include <string>
#include <math.h>
#include "enviro.h"

namespace {

    using namespace enviro;

    // MovingForward class defines speed of advance and detection of collision conditions
    class MovingForward : public State, public AgentInterface {
        public:
        void entry(const Event& e) {
            // if they collide with the knigth, emit an event "caught", and knight will 
            //get back to start point.
            notice_collisions_with("Knight", [&](Event &e) {
                 emit(Event("caught"));
            });
        }
        
        void during() { 
            track_velocity(5,0);
            if ( sensor_value(0) < 30 || sensor_value(1) < 8 || sensor_value(2) < 8 || 
            sensor_value(3) < 8 || sensor_value(4) < 8) {
                emit(Event(tick_name));
            }            
        }
        void exit(const Event& e) {}
        void tin_ring(std::string s) { tick_name = s; }
        std::string tick_name;
    };

    // Rotating class defines the rotating speed and direction
    class Rotating : public State, public AgentInterface {
        public:
        void entry(const Event& e) { 
            rate = rand() % 2 == 0 ? 2 : -2;  //Randomly select left and right
        }
        void during() {
            track_velocity(0, rate);
            if ( sensor_value(0) > 60 ) { //transfer to move forward
                emit(Event(tick_name));
            }
        }
        void exit(const Event& e) {}
        double rate;
        void tin_ring(std::string s) { tick_name = s; }
        std::string tick_name;        
    };

    // The GuardController always detects if there are new events and perform state transitions.
    class GuardController : public StateMachine, public AgentInterface {

        public:
        GuardController() : StateMachine() {

            set_initial(moving_forward);
            tick_name = "tick" + std::to_string(rand()%1000);
            add_transition(tick_name, moving_forward, rotating); 
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.tin_ring(tick_name);
            rotating.tin_ring(tick_name);

        }

        MovingForward moving_forward;
        Rotating rotating;
        std::string tick_name;

    };

    class Guard : public Agent {

        public:
        Guard(json spec, World& world) : Agent(spec, world) {
            add_process(c);
        }
        GuardController c;
    };

    DECLARE_INTERFACE(Guard);

}
