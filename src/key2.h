#ifndef __KEY2_AGENT__H
#define __KEY2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class key2Controller : public Process, public AgentInterface {

    public:
    key2Controller() : Process(), AgentInterface() {}

    void init() {
        prevent_rotation();
        notice_collisions_with("playerAgent", [&](Event &e) {
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