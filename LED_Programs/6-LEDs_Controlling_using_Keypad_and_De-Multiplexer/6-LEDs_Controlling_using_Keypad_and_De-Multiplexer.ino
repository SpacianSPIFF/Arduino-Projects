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
  pinMode(1,OUTPUT); //For DE-MUX 1G
  for(int i=10;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  digitalWrite(1,HIGH);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
    char a=customKey;
    if(a=='1')
    {
      digitalWrite(1,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(11,LOW);
      Serial.println("The first LED is ON.");
    }
    else if(a=='2')
    {
      digitalWrite(1,HIGH);
      digitalWrite(10,LOW);
      digitalWrite(11,HIGH);
      Serial.println("The second LED is ON.");
    }
    else if(a=='3')
    {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(1,LOW);
      DEMUX(0,0);
      Serial.println("The third LED is ON.");
    }
     else if(a=='4')
    {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(1,LOW);
      DEMUX(1,0);
      Serial.println("The fourth LED is ON.");
    }
     else if(a=='5')
    {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(1,LOW);
      DEMUX(0,1);
      Serial.println("The fifth LED is ON.");
    }
     else if(a=='6')
    {
      digitalWrite(10,LOW);
      digitalWrite(11,LOW);
      digitalWrite(1,LOW);
      DEMUX(1,1);
      Serial.println("The sixth LED is ON.");
    }
  }
}

void DEMUX(int x, int y)
{
  digitalWrite(12, x);
  digitalWrite(13, y);
}
