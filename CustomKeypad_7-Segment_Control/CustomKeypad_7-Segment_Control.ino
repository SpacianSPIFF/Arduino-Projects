#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  for (int i = 10; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0);
  pinMode(A1);
  pinMode(A2);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println("The key pressed is: " + customKey);
    DisplaySegment(customKey);
  }
}

void DisplaySegment(char key) {
  switch (key) {
    case '0' : //ZERO 0
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case '1' : //ONE 1
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      digitalWrite(12, 1);
      digitalWrite(13, 0);
      digitalWrite(A0, 1);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      break;
    case '2' : //TWO 2
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      break;
    case '3' : //THREE 3
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case '4' : //FOUR 4
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 1);
      digitalWrite(13, 0);
      digitalWrite(A0, 1);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      break;
    case '5' : //FIVE 5
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 1);
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case '6' : //SIX 6
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 1);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case '7' : //SEVEN 7
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 1);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      break;
    case '8' : //EIGHT 8
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case '9' : //NINE 9
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 1);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case 'A' : //A
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 1);
      digitalWrite(A2, 0);
      break;
    case 'B' : //B
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
    case 'C' : //C
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 1);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 1);
      break;
    case 'D' : //D
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      digitalWrite(13, 0);
      digitalWrite(A0, 0);
      digitalWrite(A1, 0);
      digitalWrite(A2, 0);
      break;
  }
}
