//
// Created by Facundo Barafani on 9/5/21.
//

#ifndef INCLUDE_STATE_H
#define INCLUDE_STATE_H

#pragma once

class State {
public:
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(float dt) = 0;

    virtual void pause() {};
    virtual void resume() {};

};


#endif //INCLUDE_STATE_H
