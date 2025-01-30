/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/
#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
private:
   double radians;   // 360 degrees equals 2 PI radians

   double normalize(double radians) const
   {
      while (radians < 0.0)
      {
         radians += 2.0 * M_PI;
      }

      while (radians >= 2.0 * M_PI)
      {
         radians -= 2.0 * M_PI;
      }

      return radians;
   }


   double convertToRadians(double degrees) const
   {
      return degrees * (M_PI / 180.0);
   }

   double convertToDegrees(double radians) const
   {
      return radians * (180.0 / M_PI);
   }

public:
   friend TestAcceleration;
   friend TestVelocity;
   friend TestAngle;
   friend TestLander;

   // Constructors
   Angle()
   {
      radians = 0.0;
   }

   Angle(const Angle& rhs)
   {
      radians = (rhs.radians);
   }

   Angle(double degrees)
   {
      radians = convertToRadians(degrees);
   }

   // Getters
   double getDegrees() const
   {
      return convertToDegrees(radians);
   }
   double getRadians() const
   {
      return radians;
   }

   // Setters
   void setDegrees(double degrees)
   {
      radians = normalize(convertToRadians(degrees));
   }

   void setRadians(double radians)
   {
      this->radians = normalize(radians);
   }

   void setUp()
   {
      this->radians = 0.0;
   }

   void setDown()
   {
      radians = convertToRadians(180);
   }

   void setRight()
   {
      radians = convertToRadians(90);
   }

   void setLeft()
   {
      radians = convertToRadians(270);
   }
   void reverse()
   {
      radians = normalize(radians + M_PI);
   }

   double add(double delta)
   {
      radians = normalize(radians + delta);
      return radians;
   }

};


