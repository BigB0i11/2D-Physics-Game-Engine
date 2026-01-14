#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include "Vector2.h"
#include "Body.h"

using namespace std;



        Body::Body(float m, Vector2 Pos) // Default Constructor setting up details of the Body Object
        {
            Velocity = Vector2(0,0);
            Accel = Vector2(0,0);
            Pos = Vector2(0,0);

            mass = m;
            invmass = 1/m;
        }


        void Body::ApplyForce(const Vector2& f) // Function applying force to the 2D Body
        {
            if(isStatic) // Bool condition that sets force to 0 if the object is static
            {
                Force = Vector2(0,0);
            }
            else if(isKinematic) // Bool condition that controls the force via game logic/user input
            {
                Force = f;
            }
            else // Force decided via physics
            {
                Force += f;
            }
        }

        void Body::Integrate(float deltatime) // Function that computes the velocity,acceleration and updates the position
        {
            Accel = Force / mass;

            Velocity += Accel * deltatime;

            Pos += Velocity * deltatime;

            Force =  Vector2(0,0);
        }



