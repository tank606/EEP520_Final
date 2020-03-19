#ifndef __GATE2_AGENT__H
#define __GATE2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class gate2Controller : public Process, public AgentInterface {

    public:
    gate2Controller() : Process(), AgentInterface() {}

    void init() {
        watch("key2", [this](Event e) {
            remove_agent(id());
        });
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Gate2 : public Agent {
    public:
    Gate2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    gate2Controller c;
};

DECLARE_INTERFACE(Gate2)

#endif