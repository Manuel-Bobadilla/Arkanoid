#ifndef INCLUDE_MANAGER_ANIMATION_ANIMATIONMANAGER_H
#define INCLUDE_MANAGER_ANIMATION_ANIMATIONMANAGER_H


#include <string>
#include <vector>
//#include "Container.h"

// AnimationManager conforms to iterator pattern

template <typename T, typename U>
class AnimationManager {
public:
    typedef typename std::vector<T>::iterator iter_type;
    AnimationManager(U *pData, bool reverse = false) : dataPointer(pData) {
        iterator = dataPointer->mData.begin();
    }

    void first() {
        iterator = dataPointer->mData.begin();
    };
    void next(){
        iterator++;
    };
    bool isDone(){
        return (iterator == dataPointer->mData.end());
    };
    iter_type current(){
        return iterator;
    };

    unsigned int getDelay(){
        return delay;
    }

    void incrementDelay(){
        this->delay++;
    }

private:
    U *dataPointer;
    iter_type iterator;
    unsigned int delay = 0;
};

class Data {
public:
    Data(int a = 0) : mData(a) {}

    void set_data(int a) {
        mData = a;
    }

    int data() {
        return mData;
    }

private:
    int mData;
};


#endif  //INCLUDE_MANAGER_ANIMATION_ANIMATIONMANAGER_H
