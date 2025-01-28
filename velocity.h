/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

// for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestLander;

// for add()
class Acceleration;
class Angle;

 /*********************************************
  * Velocity
  * I feel the need, the need for speed
  *********************************************/
class Velocity
{
   // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestLander;
   
public:
   // constructors
   Velocity()                     : dx(0.0), dy(0.0) { }
   Velocity(double dx, double dy)
   {
      this->dx = dx;
      this->dy = dy;
   }

   // getters
   double getDX()       const { return dx; }
   double getDY()       const { return dy; }
   double getSpeed()    const 
   {
      return sqrt(dx * dx + dy * dy);
   }

   // setters
   void setDX(double dx) { this->dx = dx; }
   void setDY(double dy) { this->dy = dy; }
   void set(const Angle& angle, double magnitude)
   {
      //COMPUTE HORIZONTAL COMPONENT
      //sin(a) = dx / total
      this->dx = magnitude * sin(angle.getRadians());
      this->dy = magnitude * cos(angle.getRadians());
   }
   void addDX(double dx) 
   {
      this->dx = this->dx + dx; 
   }
   void addDY(double dy) 
   {
      this->dy = this->dy + dy; 
   }
   void add(const Acceleration& acceleration, double time)
   {
      //v = v0 + a t
      dx = dx + acceleration.getDDX() * time;
      dy = dy + acceleration.getDDY() * time;
   }

private:
   double dx;           // horizontal velocity
   double dy;           // vertical velocity
};

