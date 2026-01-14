#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include "Vector2.h"
#include "Body.h"
#include "World.h"

using namespace std;


    

    Body* World::GetBody()
    {
        if(Bodies.empty())
        {
            return nullptr;
        }

        return Bodies.front();
    }

    float World::Deltatime()
    {
        float FPS = 60;
        dt = 1/FPS;
        return dt;
    }


    void World::User_Force(const char& c)
    {
        switch(c){
            case 'w':
                user_input = Vector2(0,1);
                break;
            case 's':
                user_input = Vector2(0,-1);
                break;
            case 'd':
                user_input = Vector2(1,0);
                break;
            case 'a':
                user_input = Vector2(-1,0);
                break;
            default:
                cout << "Invalid Movement Input" << endl;
        }

    }

    void World::Check_Body_Collision()
    {
        float collision_threshold = 0.005;

        for(int i = 0; i <= Bodies.size(); i++)
        {
            Vector2 collision_diff = Bodies[i]->Pos - Bodies[i+1]->Pos;
            if(collision_diff.magnitude() >= collision_threshold)
            {
                Bodies[i]->Collided = true;
                Bodies[i+1]->Collided = true;
            }
        }
    }

    void World::Collision_Calcs(Body& other) //AI debugged and rewritten
{
    Body* A = GetBody();
    Body* B = &other;

    // 1. Collision normal (from B to A)
    Vector2 n = (A->Pos - B->Pos).normalise();

    // 2. Relative velocity along the normal
    float vA_n = Vector2::dot(A->Velocity, n);
    float vB_n = Vector2::dot(B->Velocity, n);

    // 3. Elastic collision equations (1D along normal)
    float mA = A->mass;
    float mB = B->mass;

    float vA_n_new =
        (vA_n * (mA - mB) + 2.0f * mB * vB_n) / (mA + mB);

    float vB_n_new =
        (vB_n * (mB - mA) + 2.0f * mA * vA_n) / (mA + mB);

    // 4. Convert scalar normal velocities back to vectors
    Vector2 vA_para_new = n * vA_n_new;
    Vector2 vB_para_new = n * vB_n_new;

    // 5. Preserve perpendicular components
    Vector2 vA_perp = A->Velocity - (n * vA_n);
    Vector2 vB_perp = B->Velocity - (n * vB_n);

    // 6. Final velocities
    A->Velocity = vA_para_new + vA_perp;
    B->Velocity = vB_para_new + vB_perp;
}


    void World::Physics_Step(float dt, char inputkey)
    {
        Body* B1 = GetBody();
        Deltatime();

        B1->Force = Gravity * B1->mass;
        Vector2 drag = B1->Velocity * -k;
        B1->Force += drag;

        if(B1->isKinematic == true)
        {
            User_Force(inputkey);
            B1->ApplyForce(user_input);
            B1->Integrate(dt);
            Check_Body_Collision();
            if(B1->Collided == true)
            {
                Collision_Calcs(*Bodies[1]);
            }

        }
        else if(B1->isStatic == true)
        {
            Vector2 Static_Force = Vector2();
            B1->ApplyForce(Static_Force);
        }
        else 
        {
            B1->ApplyForce(B1->Force);
            B1->Integrate(dt);
            Check_Body_Collision();
            if(B1->Collided == true)
            {
                Collision_Calcs(*Bodies[1]);
            }

        }

    }
    







