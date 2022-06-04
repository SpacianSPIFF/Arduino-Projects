#include "LedControl.h"

const int DIN = 10;
const int CS =  9;
const int CLK = 8;

LedControl lc = LedControl(DIN, CLK, CS, 1);

// Over all variables
bool isGameOver = false;
int score = 0;
String input;
const int leftPin = 7;
const int rightPin = 6;
const int firePin = 5;
const int joystickY = A0;
const int joystickK = 4;

// Player variables
int playerX = 3;  // Tracks the centre of the 3 dots of the player
byte playerRow1, playerRow2;
int playerTimer = 0;
int playerTimerGap = 20;

// Bullet variables
int bulletY = 5;
int bulletX;
byte bulletXbyte;
String bulletState = "ready";
int bulletTimer = 0;
int bulletTimerGap = 75;

// Enemy variables
int enemiesX[4][2] = {{2, 3}, {5, 6}, {1, 2}, {4, 5}};
int enemiesY[4] = {0, 0, 1, 1};
int enemiesTimer = 0;
int enemiesTimerGap = 350;

void setup() {
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  pinMode(firePin, INPUT);
  pinMode(joystickY, INPUT);
  pinMode(joystickK, INPUT);

  lc.shutdown(0, false);
  lc.setIntensity(0, 0);
  lc.clearDisplay(0);

  spawnPlayer();
  spawnEnemies();

  Serial.begin(9600);
}

void loop() {
  while (!isGameOver) {
    // Uncomment a line for the type of control you want
    // Default is Joystick control
    // buttonControl();  // Button controls
    joystickControl();  // Joystick Controls
    // serialControl();  // Serial controls

    if (bulletState == "fire" && bulletY >= 0) {
      checkBulletCollision();
      updateBulletPos();
    }

    if (bulletY == -1) {
      // Reset bullet parameters
      bulletState = "ready";
      bulletY = 5;
      bulletTimer = 0;
    }

    updatePlayerPos();
    updateEnemyPos();
    checkEnemyCollisionWithPlayer();
  }

  lc.clearDisplay(0);
}

void spawnPlayer() {
  lc.setRow(0, 6, playerRow1);
  lc.setRow(0, 7, playerRow2);
}

void spawnEnemies() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      lc.setLed(0, enemiesY[i], enemiesX[i][j], true);
    }
  }
}

void updatePlayerPos() {
  switch (playerX) {
    case 1:
      playerRow1 = B01000000;
      playerRow2 = B11100000;
      break;
    case 2:
      playerRow1 = B00100000;
      playerRow2 = B01110000;
      break;
    case 3:
      playerRow1 = B00010000;
      playerRow2 = B00111000;
      break;
    case 4:
      playerRow1 = B00001000;
      playerRow2 = B00011100;
      break;
    case 5:
      playerRow1 = B00000100;
      playerRow2 = B00001110;
      break;
    case 6:
      playerRow1 = B00000010;
      playerRow2 = B00000111;
      break;
  }

  // Change position of player
  lc.setRow(0, 6, playerRow1);
  lc.setRow(0, 7, playerRow2);
}

void fireBullet() {
  bulletXbyte = playerRow1;
  for (int i = 0, mask = 128; i < 8; i++, mask = mask >> 1) {
    if (bulletXbyte & mask) {
      bulletX = i;
      break;
    }
  }

  // Fire bullet
  bulletState = "fire";
  lc.setLed(0, bulletY, bulletX, true);
}

void updateBulletPos() {
  bulletTimer++;
  if (bulletTimer % bulletTimerGap == 0) {
    bulletY--;
    lc.setLed(0, bulletY + 1, bulletX, false);
    lc.setLed(0, bulletY, bulletX, true);
    bulletTimer = 0;
  }
}

void checkBulletCollision() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      if (bulletX == enemiesX[i][j] && bulletY == enemiesY[i]) {
        // Reset bullet parameters
        bulletState = "ready";
        bulletY = 5;
        bulletTimer = 0;
        lc.setLed(0, bulletY, bulletX, false);

        // Delete the enemy
        toggleEnemyLed(i, false);
        enemiesY[i] = -1;

        score++;

        break;
      }
    }
  }
}

void updateEnemyPos() {
  enemiesTimer++;
  if (enemiesTimer % enemiesTimerGap == 0) {
    for (int i = 0; i < 4; i++) {
      if (enemiesY[i] % 2 == 0) {
        toggleEnemyLed(i, false);

        enemiesX[i][0]++;
        enemiesX[i][1]++;

        toggleEnemyLed(i, true);
      }
      if (enemiesY[i] % 2 != 0) {
        toggleEnemyLed(i, false);

        enemiesX[i][0]--;
        enemiesX[i][1]--;

        toggleEnemyLed(i, true);
      }
      if (enemiesX[i][1] > 7) {
        toggleEnemyLed(i, false);

        enemiesY[i]++;
        enemiesX[i][0]--;
        enemiesX[i][1]--;

        toggleEnemyLed(i, true);
      }
      if (enemiesX[i][0] < 0) {
        toggleEnemyLed(i, false);

        enemiesY[i]++;
        enemiesX[i][0]++;
        enemiesX[i][1]++;

        toggleEnemyLed(i, true);
      }
    }
  }
}

void checkEnemyCollisionWithPlayer() {
  for (int i = 0; i < 4; i++) {
    if (enemiesY[i] >= 6) {
      isGameOver = true;
      break;
    }
  }
}

void toggleEnemyLed(int i, bool value) {
  lc.setLed(0, enemiesY[i], enemiesX[i][0], value);
  lc.setLed(0, enemiesY[i], enemiesX[i][1], value);
}

void serialControl() {
  if (Serial.available() > 0) {
    input = Serial.readString();
    input.trim();
    input.toLowerCase();
    Serial.println("Command: " + input);

    if (input == "left" && playerX > 1) {
      playerX--;
    }
    else if (input == "right" && playerX < 6) {
      playerX++;
    }

    if (input == "fire" && bulletState != "fire") {
      fireBullet();
    }
  }
}

void joystickControl() {
  playerTimer++;
  if (playerTimer % playerTimerGap == 0) {
    int Y = (map(analogRead(joystickY), 0, 1023, 0, 6) - 3) / 2;
    Serial.println(Y);
    int K = !digitalRead(joystickK);
  
    if (playerX >= 1 && playerX <= 6) {
      playerX += Y;
      if (playerX < 1) {
        playerX = 1;
      }
      else if (playerX > 6) {
        playerX = 6;
      }
    }
  
    if (K && bulletState != "fire") {
      fireBullet();
    }
  }
}

void buttonControl() {
  int left = digitalRead(leftPin);
  int right = digitalRead(rightPin);
  int fire = digitalRead(firePin);

  if (left && playerX > 1) {
    playerX--;
  }
  else if (right && playerX < 6) {
    playerX++;
  }

  if (fire && bulletState != "fire") {
    fireBullet();
  }
}
