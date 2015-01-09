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

byte sequence [256], playerSequence [256], i, j, k, nextLight, nextNum, score;
boolean correct, cont, repeat, start;



void setup()                    // run once, when the sketch starts
{ 
  MeggyJrSimpleSetup();  // Required code, line 2 of 2.
  start = true;
  
}


void loop()
{
  while (start)
  {
    if (!repeat)
     {
       randomSeed(millis());
       StartScreen();
       DisplaySlate();
       delay(1000);
       ClearSlate();
       DisplaySlate();
       delay(1000);
       CheckButtonsDown();
     }
       
      if (Button_A || Button_B)  //start game
   
   {    
     
     i=0;
     
     while (i<255)  //creates pseudo random color sequence
     {
      nextNum = random(1,5);
      sequence[i]=nextNum;
      i++;
     }
  
      correct = true;
      cont = true;
      StartScreen();
      DisplaySlate();
      delay(1500);
      SetAuxLEDs(score + 1);
      start = false;
  }
  
 }
 
 if (cont && correct)  //plays back sequence until j reaches the current round
{  
  
  j=0;
  
  while (j < score + 1)
  {
    
    delay(200);
    nextLight = sequence[j];
    
    switch (nextLight)
      {
        
        case 1:
        {
        LightLeft();
        delay(200);
        StartScreen();
        j++;
        break;
        }
        
        case 2:
        {
        LightRight();
        delay(200);
        StartScreen();
        j++;
        break;
        }
        
        case 3:
        {
        LightUp();
        delay(200);
        StartScreen();
        j++;
        break;
        }
        
        case 4:
        {
        LightDown();
        delay(200);
        StartScreen();
        j++;
        break;
        }
        
      }
      
    Tone_Update();
    cont = false;  //sentinel   
 }
 

if(!cont && correct);  //Player uses arrow keys to enter sequence.  If incorrect at any point game ends immediately.
{
  k=0;
 
  while (k < score + 1 && correct )
  {
  
    CheckButtonsDown();
  
    if (Button_Left)
    {
      
     LightLeft();
     StartScreen();
     playerSequence[k] = 1;
     
     if (playerSequence[k] == sequence[k])
     {
      correct = true;
      k++;
     }
     
     else
     {
      correct = false;
      end();
     }
     
    }
     
    if (Button_Right)
    {
      
     LightRight();
     StartScreen();
     playerSequence[k] = 2;
     
     if (playerSequence[k] == sequence[k])
     {
      correct = true;
      k++;
     }
     
      else
     {
      correct = false;
      end();
    }
    
  }
  
    if (Button_Up)
    {
    LightUp();
     StartScreen();
     playerSequence[k] = 3;
     
    if (playerSequence[k] == sequence[k])
    {
    correct = true;
    k++;
    }
    
    else
    {
     correct = false;
     end();
    }
    
   }
  
  if (Button_Down)
  {
   LightDown();
   StartScreen();
   playerSequence[k] = 4;
   
   if (playerSequence[k] == sequence[k])
    {
     correct = true;
     k++;
    }
    
    else
    {
      correct = false;
      end();
    }
    
  }
  
 }
  
 if (correct)
 {
   cont = true; //sentinel
   score++;
   SetAuxLEDs(score + 1);
   delay(500);
 }
   
 }
 
  
    
}
  
DisplaySlate();
Tone_Update();

}




   

 

void end()
{
 Tone_Start(5,1000);
 ClearSlate();
 redX;
 DisplaySlate();
 delay(1000);
 Tone_Update();

  while(!correct && !start)
    {
     Up();
     SetAuxLEDs(0);
     delay(100);
     ClearSlate();
     redX();
     Left();
     SetAuxLEDs(score + 1);
     delay(100);
     ClearSlate();
     redX();
     Down();
     SetAuxLEDs(0);
     delay(100);
     ClearSlate();
     redX();
     Right();
     SetAuxLEDs(score + 1);
     delay(100);
     ClearSlate();
     redX();
     CheckButtonsPress();
     
        if (Button_A || Button_B) //reset game
        {
          ClearSlate();
          DisplaySlate();
          repeat = true;
          score = 0;
          start = true; 
        }
        
     }   
     
}
  
 

  


void Up()                // Draw Up arrow.
{
  DrawPx(3,6,Red);  
  DrawPx(3,5,Red);
  DrawPx(4,6,Red);
  DrawPx(4,5,Red);
  DrawPx(2,5,Red);
  DrawPx(3,7,Red);
  DrawPx(4,7,Red);
  DrawPx(5,5,Red);
  DrawPx(2,6,Red);
  DrawPx(5,6,Red);
  DisplaySlate();
}

void Down()
{
  DrawPx(3,1,Violet);  
  DrawPx(3,2,Violet);
  DrawPx(4,1,Violet);
  DrawPx(4,2,Violet);
  DrawPx(2,2,Violet);
  DrawPx(3,0,Violet);
  DrawPx(4,0,Violet);
  DrawPx(5,2,Violet);
  DrawPx(2,1,Violet);
  DrawPx(5,1,Violet);
  DisplaySlate();
}

void Left()
{
  DrawPx(0,4,Green);
  DrawPx(0,3,Green);
  DrawPx(2,2,Green);
  DrawPx(1,2,Green);
  DrawPx(1,5,Green);
  DrawPx(2,5,Green);
  DrawPx(1,4,Green);  
  DrawPx(1,3,Green);
  DrawPx(2,4,Green);
  DrawPx(2,3,Green);
  DisplaySlate();
}

void Right()
{
  DrawPx(6,4,Yellow);  
  DrawPx(6,3,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(7,3,Yellow);
  DrawPx(7,4,Yellow);
  DrawPx(5,5,Yellow);
  DrawPx(6,2,Yellow);
  DrawPx(6,5,Yellow);
  DisplaySlate();
}

void LightUp()                // Draw Up arrow.
{
  DrawPx(3,6,Red);  
  DrawPx(3,5,Red);
  DrawPx(4,6,Red);
  DrawPx(4,5,Red);
  DrawPx(2,5,Red);
  DrawPx(3,7,Red);
  DrawPx(4,7,Red);
  DrawPx(5,5,Red);
  DrawPx(2,6,Red);
  DrawPx(5,6,Red);
  DisplaySlate();
  
   Tone_Start(ToneD5, 200);
  DisplaySlate();
  delay(205);
  Tone_Update();
}

void LightDown()
{
  DrawPx(3,1,Violet);  
  DrawPx(3,2,Violet);
  DrawPx(4,1,Violet);
  DrawPx(4,2,Violet);
  DrawPx(2,2,Violet);
  DrawPx(3,0,Violet);
  DrawPx(4,0,Violet);
  DrawPx(5,2,Violet);
  DrawPx(2,1,Violet);
  DrawPx(5,1,Violet);
  DisplaySlate();
  
   Tone_Start(ToneD5, 200);
  DisplaySlate();
  delay(205);
  Tone_Update();
}

void LightLeft()
{
  DrawPx(0,4,Green);
  DrawPx(0,3,Green);
  DrawPx(2,2,Green);
  DrawPx(1,2,Green);
  DrawPx(1,5,Green);
  DrawPx(2,5,Green);
  DrawPx(1,4,Green);  
  DrawPx(1,3,Green);
  DrawPx(2,4,Green);
  DrawPx(2,3,Green);
  DisplaySlate();
  
   Tone_Start(ToneD5, 200);
  DisplaySlate();
  delay(205);
  Tone_Update();
}

void LightRight()
{
  DrawPx(6,4,Yellow);  
  DrawPx(6,3,Yellow);
  DrawPx(5,4,Yellow);
  DrawPx(5,3,Yellow);
  DrawPx(5,2,Yellow);
  DrawPx(7,3,Yellow);
  DrawPx(7,4,Yellow);
  DrawPx(5,5,Yellow);
  DrawPx(6,2,Yellow);
  DrawPx(6,5,Yellow);
  DisplaySlate();
  
   Tone_Start(ToneD5, 200);
  DisplaySlate();
  delay(205);
  Tone_Update();
}


void redX()
{
  
  DrawPx(0,0,Red);
  DrawPx(0,1,Red);
  DrawPx(1,1,Red);
  DrawPx(1,0,Red);
  DrawPx(6,0,Red);
  DrawPx(7,0,Red);
  DrawPx(7,1,Red);
  DrawPx(6,1,Red);
  DrawPx(2,2,Red);
  DrawPx(5,2,Red);
  DrawPx(3,3,Red);
  DrawPx(4,3,Red);
  DrawPx(3,4,Red);
  DrawPx(4,4,Red);
  DrawPx(2,5,Red);
  DrawPx(5,5,Red);
  DrawPx(0,6,Red);
  DrawPx(1,6,Red);
  DrawPx(6,6,Red);
  DrawPx(7,6,Red);
  DrawPx(0,7,Red);
  DrawPx(1,7,Red);
  DrawPx(6,7,Red);
  DrawPx(7,7,Red);
  DisplaySlate();  
}

void StartScreen()
{
  DrawPx(0,4,White);//left
  DrawPx(0,3,White);
  DrawPx(2,2,White);
  DrawPx(1,2,White);
  DrawPx(1,5,White);
  DrawPx(2,5,White);
  DrawPx(1,4,White);  
  DrawPx(1,3,White);
  DrawPx(2,4,White);
  DrawPx(2,3,White);

  
  DrawPx(6,4,White);  //right
  DrawPx(6,3,White);
  DrawPx(5,4,White);
  DrawPx(5,3,White);
  DrawPx(5,2,White);
  DrawPx(7,3,White);
  DrawPx(7,4,White);
  DrawPx(5,5,White);
  DrawPx(6,2,White);
  DrawPx(6,5,White);
  
  DrawPx(3,6,White);  //up
  DrawPx(3,5,White);
  DrawPx(4,6,White);
  DrawPx(4,5,White);
  DrawPx(2,5,White);
  DrawPx(3,7,White);
  DrawPx(4,7,White);
  DrawPx(5,5,White);
  DrawPx(2,6,White);
  DrawPx(5,6,White);
  
  DrawPx(3,1,White);  //down
  DrawPx(3,2,White);
  DrawPx(4,1,White);
  DrawPx(4,2,White);
  DrawPx(2,2,White);
  DrawPx(3,0,White);
  DrawPx(4,0,White);
  DrawPx(5,2,White);
  DrawPx(2,1,White);
  DrawPx(5,1,White);
  
  DisplaySlate();
}


  
