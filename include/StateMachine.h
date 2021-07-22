//
// Created by Facundo Barafani on 9/5/21.
//

#ifndef PROJECTTEMAPLATE_STATEMACHINE_H
#define PROJECTTEMAPLATE_STATEMACHINE_H

#pragma once

#include <memory>
#include <stack>
#include "State.h"

typedef std::unique_ptr<State> StateRef;
class StateMachine {
private:
    std::stack<StateRef> _states;
    StateRef _newState;
    bool _isRemoving;
    bool _isReplacing;
    bool _isAdding;
public:
    StateMachine() {}
    ~StateMachine() {}
    void addState(StateRef newState, bool isReplacing = true);
    void removeState();
    void processStateChanges();
    StateRef &getActiveState();
};


#endif//PROJECTTEMAPLATE_STATEMACHINE_H
