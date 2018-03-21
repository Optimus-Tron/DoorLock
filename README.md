#include <Servo.h>
#include <Keypad.h>

Servo Motor;
/*Enter security code here*/
char* code = "160";
int position = 0;

/* Generate keypad data */
const byte keypad_rows = 4;
const byte keypad_columns = 4;
char keys[keypad_rows][keypad_columns] = 
{
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

/*Declare pins for keypad*/
byte rows[keypad_rows] = { 8, 7, 6, 5 };
byte columns[keypad_columns] = { 4, 3, 2, 1 };
Keypad keypad = Keypad( makeKeymap(keys), rows, columns, keypad_rows, keypad_columns);

/*Setup servo*/
void setup()
{
Motor.attach(9);
LockedPosition(true);
}

/*constantly running - check passcode */
void loop()
{
char key = keypad.getKey();
if (key == '*' || key == '#')
{
position = 0;
LockedPosition(true);
}

if (key == password[position])
{
position ++;
}

if (position == 3)
{
LockedPosition(false);
}
delay(100);
}

void LockedPosition(int locked)
{
if (locked)
{
Motor.write(9);
}
else
{
Motor.write(90);
}
}
