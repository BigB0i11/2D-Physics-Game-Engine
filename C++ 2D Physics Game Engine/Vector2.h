#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>



struct Vector2 {
    float x, y;

    // Constructors

    Vector2(); 
    Vector2(float xi, float yi); 
    Vector2(const Vector2& other); 

    // Basic Operation Overloads

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(const Vector2& other) const;
    Vector2 operator/(const Vector2& other) const;


    // Scalar Calculation Operation Overloads
    
    Vector2 operator*(float s) const;
    Vector2 operator/(float s) const;



    // Compound Operation Overloads
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);


    // Functions

    float magnitude() const;  // Function Calculation the magnitude of a given vector
    Vector2 normalise() const; // Function calculating the unit vector
    static float dot(const Vector2& a, const Vector2& b); // Dot Product Function

};

#endif
