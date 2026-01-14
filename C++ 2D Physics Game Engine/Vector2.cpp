#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include "Vector2.h"

using namespace std;




    Vector2::Vector2(){ // Default Constructor
        x = 0.0f;
        y = 0.0f;
    }

    Vector2::Vector2(float xi, float yi){ // 2 input constructor
        x = xi;
        y = yi;
    }

    Vector2::Vector2(const Vector2& other){ // Copy Constructor
        x = other.x;
        y = other.y;
    }

    // Operation Overloads

    Vector2 Vector2::operator+(const Vector2& other) const
    {
        Vector2 c;

        c.x = x + other.x;
        c.y = y + other.y;

        return c;
    }

    Vector2 Vector2::operator-(const Vector2& other) const
    {
        Vector2 c;

        c.x = x - other.x;
        c.y = y - other.y;

        return c;
    }

    Vector2 Vector2::operator*(const Vector2& other) const
    {
       Vector2 c;

        c.x = x * other.x;
        c.y = y * other.y;

        return c;
    }

        Vector2 Vector2::operator/(const Vector2& other) const
    {
     Vector2 c;

        c.x = x / other.x;
        c.y = y / other.y;

        return c;
    }

    Vector2 Vector2::operator*(float s) const
    {
        return Vector2((x*s),(y*s));
    }

    Vector2 Vector2::operator/(float s) const
    {
        return Vector2((x/s),(y/s));
    }

    Vector2& Vector2::operator+=(const Vector2& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    float Vector2::magnitude() const  // Function Calculation the magnitude of a given vector
    {
        float mag,x2,y2;

        x2 = x*x;
        y2 = y*y;

        mag = sqrt(x2+y2);

        return mag;

    }

    Vector2 Vector2::normalise() const // Function calculating the unit vector
    {
        float mag;
        Vector2 nv;

        mag = magnitude();

        if (mag == 0.0){
            return Vector2(0.0,0.0);
        }

       nv.x = x / mag;
       nv.y = y / mag;
       
       return nv;
    }


     float Vector2::dot(const Vector2& a, const Vector2& b) // Dot Product Function
    {
        return ((a.x * b.x) + (a.y * b.y));
    }


