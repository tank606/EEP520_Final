#ifndef __KEY_AGENT__H
#define __KEY_AGENT__H 

#include "enviro.h"

using namespace enviro;

class keyController : public Process, public AgentInterface {

    public:
    keyController() : Process(), AgentInterface() {}

    void init() {
        prevent_rotation();
        notice_collisions_with("playerAgent", [&](Event &e) {
            emit(Event("key1"));
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