/*
  Copy_Me.pde
 
 Example file using the The Meggy Jr Simplified Library (MJSL)
  from the Meggy Jr RGB library for Arduino
   
 Blink a damned LED.
   
   
 
 Version 1.25 - 12/2/2008
 Copyright (c) 2008 Windell H. Oskay.  All right reserved.
 http://www.evilmadscientist.com/
 
 This library is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this library.  If not, see <http://www.gnu.org/licenses/>.
 	  
 */


 

/*
 * Adapted from "Blink,"  The basic Arduino example.  
 * http://www.arduino.cc/en/Tutorial/Blink
 */
 
 /*
* loop set 0 for computer play
 Display Sequence for level then flip to loop set 1 for player player
* loop set 1 for player play
  make sure player get sequence correct
* lvl array 
* completion array (checks whether player got sequence correct)
* Do a DidIwin array to check the sequences then return if true or false 
* Then make DrawUp, DrawDown, DrawLeft, DrawRight, DrawA, DrawB.
  to show up on the screen.
* 
*/





#include <MeggyJrSimple.h> // Required code, line 1 of 2.

int level = 1
int lights = 2



void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();      // Required code, line 2 of 2.
}


void loop()
{
}


