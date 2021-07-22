#ifndef INCLUDE_MANAGER_ANIMATION_CONTAINER_H
#define INCLUDE_MANAGER_ANIMATION_CONTAINER_H

#include <string>
#include <vector>
#include "AnimationManager.h"

template <class T>
class Container {
    friend class AnimationManager<T,Container>;
public:
    void add(T a){
        mData.push_back(a);
    }

    bool isEmpty(){
        return mData.empty();
    }

    AnimationManager<T,Container> *createIterator(){
        return new AnimationManager<T,Container>(this);
    };

    AnimationManager<T,Container> &getIterator(){
        return AnimationManager<T,Container>(this);
    }

private:
    std::vector<T> mData;
};


#endif//PROJECTTEMAPLATE_CONTAINER_H
