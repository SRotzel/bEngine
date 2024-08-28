#ifndef B_OBJECT_H_
#define B_OBJECT_H_

#include <stdio.h>
#include "bUtil.h"

class bObject {
public:
    bObject();
    bObject(i16 _id, v2 _position, v2 _dimension);
    ~bObject();

    virtual void Awake() {}
    virtual void Tick()  {}
    virtual void End()   {}

    v2 getPosition();
    v2 getDirection();
    v2 getDimensions();
    i16 getID();

protected:
    v2 position, direction, plane, dimension;
    i16 id;
};
typedef bObject* bPipeline;

#endif