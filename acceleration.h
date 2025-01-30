/***********************************************************************
 * Header File:
 *    ACCELERATION 
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/



#pragma once
#include "angle.h"

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;
class Angle;


/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration

public:
   // constructors
   Acceleration()
   {
      ddx = 0.0;
      ddy = 0.0;
   }

   Acceleration(double ddx, double ddy)
   {
      this->ddx = ddx;
      this->ddy = ddy;
   }

   // getters
   double getDDX()   const
   {
      return ddx;
   }

   double getDDY()   const
   {
      return ddy;
   }

   // setters                        
   void setDDX(double ddx)
   {
      this->ddx = ddx;
   }
   void setDDY(double ddy)
   {
      this->ddy = ddy;
   }
   void set(const Angle& a, double magnitude)
   {
      ddy = magnitude * cos(a.getRadians());
      ddx = magnitude * sin(a.getRadians());
   };
   void addDDX(double ddx)
   {
      this->ddx = ddx + this->ddx;
   }
   void addDDY(double ddy)
   {
      this->ddy = ddy + this->ddy;
   }
   void add(const Acceleration& rhs)
   {
      this->ddx += rhs.ddx;
      this->ddy += rhs.ddy;
   }
};




