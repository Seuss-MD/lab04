/**********************************************************************
 * LAB 06
 * Lunar Lander simulation. This is the Game class and main()
 **********************************************************************/

#include "position.h"    // everything should have a point
#include "angle.h"       // angle of the lander
#include "uiInteract.h"  // for INTERFACE
#include "uiDraw.h"      // for RANDOM and DRAW*
#include "ground.h"      // for GROUND
#include "test.h"        // for the unit tests
#include <cmath>         // for SQRT
#include <cassert>       // for ASSERT
using namespace std;

/*************************************************************************
 * SIMULATOR
 * Everything pertaining to the simulator.
 *************************************************************************/
class Simulator
{
public:
   // set up the simulator and element positions
   Simulator(const Position & posUpperRight) :
      ground   (posUpperRight),
      posLander(posUpperRight.getX() / 2.0, posUpperRight.getY() / 2.0),
      posStar  (300.0, 300.0) {}
       
   // display stuff on the screen
   void display();

   // turn
   void turnRight()  { a.add(-0.05); }
   void turnLeft()   { a.add( 0.05); }

   // blink phase for star
   void blink() { phase+=10; }

private:
   unsigned char phase = 0;
   Angle a;
   Ground ground;
   Position posUpperRight;
   Position posLander;
   Position posStar;
};

/**********************************************************
 * DISPLAY
 * Draw on the screen
 **********************************************************/
void Simulator::display()
{
   ogstream gout;

   // draw the ground
   ground.draw(gout);

   // draw the lander
   gout.drawLander(posLander, a.getRadians());

   // draw a star
   gout.drawStar(posStar, phase);
}


/*************************************
 * CALLBACK
 * Handle one frame of the simulator
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Simulator * pSimulator = (Simulator *)p;

   // draw the game
   pSimulator->display();

   // handle input
   if (pUI->isRight())
      pSimulator->turnRight();   // rotate right here
   if (pUI->isLeft())
      pSimulator->turnLeft();   // rotate left here

   // change phase
   pSimulator->blink();
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my LM type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run the unit tests
   testRunner();

   
   // Initialize OpenGL
   Position posUpperRight(400, 400);
   Interface ui("Lunar Lander", posUpperRight);

   // Initialize the game class
   Simulator simulator(posUpperRight);

   // set everything into action
   ui.run(callBack, (void *)&simulator);

   return 0;
}
