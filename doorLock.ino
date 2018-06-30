//MADE BY: CHRIS ADAMS
//2018 - MCMASTER UNIVERSITY

#include <Keypad.h>
#include <Servo.h>

Servo servoMotor
//change the code here to adjust the entry password
char* code = "6969";
byte position = 0;

//--------------- KEYPAD CODE -------------------//
const byte rows = 4; //FOUR ROWS
const byte cols = 3; //FOUR COLUMNS

//CREATE MATRIX FOR KEYPAD
char keys[rows][cols] =
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'},  
};

//DECLARE PINS FOR KEYPAD
byte rowPins[rows] = {5, 4, 3, 2};
byte colPins[cols] = {9, 8, 7, 6}; 

//MAP KEYPAD 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );


void setup() {
servoMotor.attach(10)
locked(true);
}

void loop()
{
  char key = keypad.getKey();
  
  //LOCK THE DOOR WITH AUXILLARY KEYS
  if (key ==  '*' || key == '#')
    {
      position = 0; \\reset the code if you input a number incorrectly
      locked(true);
    }
    
  //CHECK IF PASSWORD IS INPUT CORRECTLY
  if (key == code[position])
    {
      position++;
    }

  //CHECK IF FULL PASSWORD INPUTTED
  if (position >=4)
    {
      locked(false);
    }

   delay(250);
}

//-----------LOCK FUNCTION-------//
void locked(int lock)
{
  if (lock)
  {
    servoMotor.write(0);    
  }
  else
  {
    servoMotor.write(90)
  }
}

