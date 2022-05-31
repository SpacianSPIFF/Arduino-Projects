#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 12}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    Serial.println(customKey);
    char a = customKey;
    if (a == '1')
    {
      setcolour(255, 0, 0); //RED
      Serial.println("The colour is RED.");
    }
    else if (a == '2')
    {
      setcolour(0, 255, 0); //GREEN
      Serial.println("The colour is GREEN.");
    }
    else if (a == '3')
    {
      setcolour(0, 0, 255); //BLUE
      Serial.println("The colour is BLUE.");
    }
    else if (a == '4')
    {
      setcolour(255, 6, 0); //ORANGE
      Serial.println("The colour is ORANGE.");
    }
    else if (a == '5')
    {
      setcolour(255, 0, 7); //PINK
      Serial.println("The colour is PINK.");
    }
    else if (a == '6')
    {
      setcolour(255, 66, 0); //YELLOW
      Serial.println("The colour is YELLOW.");
    }
    else if (a == '7')
    {
      setcolour(0, 255, 255); //LIGHT BLUE
      Serial.println("The colour is LIGHT BLUE.");
    }
    else if (a == '8')
    {
      setcolour(102, 0, 204); //LAVENDER
      Serial.println("The colour is LAVENDER.");
    }
    else if (a == '9')
    {
      setcolour(0, 190, 100); //SEA GREEN
      Serial.println("The colour is SEA GREEN.");
    }
    else if (a == '0')
    {
      setcolour(255, 115, 155); //WHITE
      Serial.println("The colour is WHITE.");
    }
    else if (a == 'D')
    {
      setcolour(0, 0, 0); //LED=OFF
      Serial.println("The LED is OFF.");
    }
  }
}

void setcolour(int red, int green, int blue)
{
  analogWrite(9, red);
  analogWrite(10, green);
  analogWrite(11, blue);
}
