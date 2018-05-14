#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "MyMath.h"

// TEST_CASE ( "Factorials are computed", "[factorial]") {
//   REQUIRE( Factorial(1) == 1 );
//   REQUIRE( Factorial(0) == 1 );


// }

TEST_CASE ( "Rectangles are tested", "[rectangle]") {
    Point A = {0,0};
    Point B = {4,4};

    Point C = {0,0};
    Point D = {3,5};

    Point E = {3,5};
    Point F = {0,0};



    Rectangle * temp = new Rectangle(A,B);
    Rectangle * temp2 = new Rectangle(C,D);
    Rectangle * temp3 = new Rectangle(E,F);

    SECTION("testing the ctor with Expand"){
      /*
      trying to check if p1 is actualy bottom left and p2 top right
      the two temps are make the same rectangle so expanding it should 
      give is the same area, but this doesnt, this is breacuse
      the ctor sets p1 to p2 at the wrong spots
      */
      temp2->Expand();
      temp3->Expand();
    
      REQUIRE( temp2->CalculateArea() == temp3->CalculateArea() );

    } // ctor sets its arguments to the wrong spots in the rectangle, wrong p1 p2 values

    SECTION("Testing ctor with Shrinking"){
      /*
      Trying to check if p1 is actualy bottom left and p2 top right
      the two temps are make the same rectangle so Shrinking it should 
      give is the same area, but this doesnt, this is breacuse
      the ctor sets p1 to p2 at the wrong spots
      */

      
      temp2->Shrink();
      temp3->Shrink();

      REQUIRE( temp2->CalculateArea() == temp3->CalculateArea() );
    } // ctor sets its arguments to the wrong spots in the rectangle, wrong p1 p2 values

    SECTION("Testing overlap function") {
      /*
        I made one Rectangle with points (0,0),(4,4) and a second rectangle with 
        points (1,1),(2,2) these two rectangles points never overlaps with eachother
        but it returns true when calling OverLaps. 
        even tho this rectangle doesnt share any points with the other one 

      */


    Point t1 = {1,1};
    Point t2 = {2,2};
    Rectangle * temp4 = new Rectangle(t1,t2);

    REQUIRE(temp->Overlaps(*temp4) == false); //should return false, returns true
    REQUIRE(temp4->Overlaps(*temp) == false); //should return false, returns true

    }

}
