#ifndef BODY_H
#define BODY_H


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include "Vector2.h"


class Body{

    public:
    bool isStatic;
    bool isKinematic;
    bool Collided;
    float mass;
    float invmass;
    Vector2 Pos;
    Vector2 Velocity;
    Vector2 Accel;
    Vector2 Force;

        //Constructors
        Body(float m, Vector2 Pos);

        // Functions
        void ApplyForce(const Vector2& f);
        void Integrate(float deltatime);

};

#endif