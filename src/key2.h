#ifndef __KEY2_AGENT__H
#define __KEY2_AGENT__H 

#include "enviro.h"

using namespace enviro;

//Same with keycontroller, key2Controller detects the collisions with knights. 
//After a collision, remove itself and throw an event to remove the corresponding door
class key2Controller : public Process, public AgentInterface {

    public:
    key2Controller() : Process(), AgentInterface() {}

    void init() {
        prevent_rotation();
        notice_collisions_with("Knight", [&](Event &e) {
            emit(Event("key2"));
            remove_agent(id());
        });   
    }

    void start() {}
    void update() {}
    void stop() {}

};

class Key2 : public Agent {
    public:
    Key2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    key2Controller c;
};

DECLARE_INTERFACE(Key2)

#endif