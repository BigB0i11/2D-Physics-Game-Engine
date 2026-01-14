#include <iostream>
#include <fstream>
#include <vector>
#include "World.h"
#include "Body.h"
#include "Vector2.h"

int main()
{
    // -----------------------------
    // Simulation parameters
    // -----------------------------
    const float dt = 1.0f / 60.0f;   // fixed timestep
    const int steps = 300;           // ~5 seconds
    const char noInput = ' ';        // neutral input

    // -----------------------------
    // Create world
    // -----------------------------
    World world;

    // -----------------------------
    // Create bodies
    // -----------------------------
    Body* bodyA = new Body(1.0f, Vector2(0.0f, 10.0f));   // dropped body
    Body* bodyB = new Body(2.0f, Vector2(0.0f, 20.0f));   // heavier body

    bodyA->Velocity = Vector2(2.0f, 0.0f);  // horizontal launch
    bodyB->Velocity = Vector2(0.0f, 0.0f);  // straight drop

    // -----------------------------
    // Add bodies to world
    // -----------------------------
    world.Bodies.push_back(bodyA);
    world.Bodies.push_back(bodyB);

    // -----------------------------
    // Open CSV file
    // -----------------------------
    std::ofstream file("gravity_demo_output.csv");
    file << "time,body,x,y,vx,vy\n";

    float time = 0.0f;

    // -----------------------------
    // Simulation loop
    // -----------------------------
    for (int i = 0; i < steps; i++)
    {
        world.Physics_Step(dt, noInput);

        // Log each body
        for (size_t b = 0; b < world.Bodies.size(); b++)
        {
            Body* body = world.Bodies[b];

            file << time << ","
                 << b << ","
                 << body->Pos.x << ","
                 << body->Pos.y << ","
                 << body->Velocity.x << ","
                 << body->Velocity.y << "\n";
        }

        time += dt;
    }

    file.close();

    // -----------------------------
    // Cleanup
    // -----------------------------
    for (Body* body : world.Bodies)
        delete body;

    world.Bodies.clear();

    std::cout << "Simulation complete. Output written to gravity_demo_output.csv\n";
    return 0;
}

// AI Generated Demo Program
