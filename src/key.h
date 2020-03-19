#ifndef __KEY_AGENT__H
#define __KEY_AGENT__H 

#include "enviro.h"

using namespace enviro;

//keyController detects the collisions with knights. 
//After a collision, remove itself and throw an event to remove the corresponding door
class keyController : public Process, public AgentInterface {

    public:
    keyController() : Process(), AgentInterface() {}

    void init() {
        prevent_rotation();
        notice_collisions_with("Knight", [&](Event &e) {
            emit(Event("key1")); //in order to remove gate
            remove_agent(id());
        });   
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Key : public Agent {
    public:
    Key(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    keyController c;
};

DECLARE_INTERFACE(Key)

#endif