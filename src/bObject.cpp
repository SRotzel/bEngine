#include "bObject.h"

bObject::bObject() { 
    this->id = 1000; 
    this->position  = (v2) {0.0f, 0.0f}; 
    this->dimension = (v2) {100.0f, 100.0f};
}

bObject::bObject(i16 _id, v2 _position, v2 _dimension) {
    this->id = _id;
    this->position = _position;
    this->dimension = _dimension;
}

v2 bObject::getPosition() { return this->position; }
v2 bObject::getDirection() { return this->direction; }
v2 bObject::getDimensions() { return this->dimension; }