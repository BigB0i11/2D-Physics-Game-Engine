# 2D Physics Game Engine

A lightweight 2D physics engine implemented in C++ for simulating rigid body dynamics, collisions, and vector-based movement. This project provides a foundation for building physics-driven games or simulations.

## Features

- **Rigid Body Simulation**: Manage multiple bodies with properties like position, velocity, and mass.
- **Vector Operations**: Utility class for 2D vector math, including addition, scaling, and normalization.
- **World Management**: Handles the update loop for all bodies, collision detection, and physics integration.
- **Simple API**: Easy-to-use interfaces to create, update, and query bodies and the physics world.

## Project Structure

├── Body.cpp # Defines the Body class for physical entities
├── Vector2.cpp # 2D vector utility class for vector math
├── World.cpp # World class managing all physics objects and updates
└── README.md # Project documentation


### Key Classes

- **Vector2**  
  Handles 2D vector operations (addition, subtraction, scaling, dot product, etc.) for movement and physics calculations.

- **Body**  
  Represents a rigid body with attributes such as position, velocity, acceleration, mass, and forces. Supports basic physics updates.

- **World**  
  Manages all bodies, updates the physics state each frame, and applies simple collision detection and response.

## Getting Started

### Prerequisites

- C++17 compatible compiler (e.g., GCC, Clang, MSVC)
- CMake or Makefile for building (optional, can compile manually)

### Compilation Example

```bash
g++ -std=c++17 -o physics_sim Body.cpp Vector2.cpp World.cpp main.cpp
./physics_sim
#include "Vector2.cpp"
#include "Body.cpp"
#include "World.cpp"

int main() {
    World world;

    Body ball;
    ball.position = Vector2(0.0f, 0.0f);
    ball.velocity = Vector2(1.0f, 2.0f);
    ball.mass = 1.0f;

    world.addBody(ball);

    for (int i = 0; i < 100; i++) {
        world.update(0.016f); // Update with 16ms timestep
        std::cout << "Ball position: " << ball.position.x << ", " << ball.position.y << std::endl;
    }

    return 0;
}



