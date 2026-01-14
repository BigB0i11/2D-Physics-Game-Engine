#ifndef WORLD_H
#define WORLD_H


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include "Vector2.h"
#include "Body.h"



class World{
    private:
    Vector2 Gravity = Vector2(0,-9.81);
    Vector2 drag = Vector2(0,0);
    Vector2 user_input = Vector2(0,0);
    float dt;
    float k = 0.5f;
    public:
    std::vector<Body*> Bodies;

   

    Body* GetBody();
    float Deltatime();
    void User_Force(const char& c);
    void Check_Body_Collision();
    void Collision_Calcs(Body& other);
    void Physics_Step(float dt, char inputkey);
    
};

#endif