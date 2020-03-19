#ifndef __GATE_AGENT__H
#define __GATE_AGENT__H 

#include "enviro.h"

using namespace enviro;

class gateController : public Process, public AgentInterface {

    public:
    gateController() : Process(), AgentInterface() {}

    void init() {
        watch("key1", [this](Event e) {
            remove_agent(id());
        });
    }
    void start() {}
    void update() {}
    void stop() {}

};

class Gate : public Agent {
    public:
    Gate(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    gateController c;
};

DECLARE_INTERFACE(Gate)

#endif