#include<LiquidCrystal.h>

#define B0  31
#define C1  33
#define CS1 35
#define D1  37
#define DS1 39
#define E1  41
#define F1  44
#define FS1 46
#define G1  49
#define GS1 52
#define A1  55
#define AS1 58
#define B1  62
#define C2  65
#define CS2 69
#define D2  73
#define DS2 78
#define E2  82
#define F2  87
#define FS2 93
#define G2  98
#define GS2 104
#define A2  110
#define AS2 117
#define B2  123
#define C3  131
#define CS3 139
#define D3  147
#define DS3 156
#define E3  165
#define F3  175
#define FS3 185
#define G3  196
#define GS3 208
#define A3  220
#define AS3 233
#define B3  247
#define C4  262
#define CS4 277
#define D4  294
#define DS4 311
#define E4  330
#define F4  349
#define FS4 370
#define G4  392
#define GS4 415
#define A4  440
#define AS4 466
#define B4  494
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5  880
#define AS5 932
#define B5  988
#define C6  1047
#define CS6 1109
#define D6  1175
#define DS6 1245
#define E6  1319
#define F6  1397
#define FS6 1480
#define G6  1568
#define GS6 1661
#define A6  1760
#define AS6 1865
#define B6  1976
#define C7  2093
#define CS7 2217
#define D7  2349
#define DS7 2489
#define E7  2637
#define F7  2794
#define FS7 2960
#define G7  3136
#define GS7 3322
#define A7  3520
#define AS7 3729
#define B7  3951
#define C8  4186
#define CS8 4435
#define D8  4699
#define DS8 4978
#define REST 0

#define X_UP   0
#define X_DOWN 1020
#define Y_UP   0
#define Y_DOWN 1020
#define ORIGIN 502
#define ERR    4

#define HOME(m, n)  ((((m) >= ORIGIN) && ((m) <= (ORIGIN + 4)))   && (((n) >= ORIGIN) && ((n) <= (ORIGIN + ERR)))) ? (true) : (false)
#define UP(m, n)    ((((m) >= ORIGIN) && ((m) <= (ORIGIN + ERR))) && (((n) >= Y_UP)   && ((n) <= (Y_UP + ERR))))   ? (true) : (false)
#define DOWN(m, n)  ((((m) >= ORIGIN) && ((m) <= (ORIGIN + ERR))) && (((n) >= Y_DOWN) && ((n) <= (Y_DOWN + ERR)))) ? (true) : (false)
#define LEFT(m, n)  ((((m) >= X_UP)   && ((m) <= (X_UP + ERR)))   && (((n) >= ORIGIN) && ((n) <= (ORIGIN + ERR)))) ? (true) : (false)
#define RIGHT(m, n) ((((m) >= X_DOWN) && ((m) <= (X_DOWN + ERR))) && (((n) >= ORIGIN) && ((n) <= (ORIGIN + ERR)))) ? (true) : (false)

//MARY HAD A LITTLE LAMB
//int notes[] = {E4, 750, D4, 250, C4, 500, D4, 500, E4, 500, E4, 500, E4, 1000, D4, 500, D4, 500, D4, 1000, E4, 500, G4, 500, G4, 1000, E4, 750, D4, 250, C4, 500, D4, 500, E4, 500, E4, 500, E4, 500, E4, 500, D4, 500, D4, 500, E4, 500, D4, 500, C4, 2000}; 
//CRAZY FROG
int notes[] = {D4, 500, F4, 375, D4, 250, D4, 250, G4, 500, D4, 500, C4, 500, D4, 500, A4, 375, D4, 250, D4, 250, AS4, 250, A4, 500, F4, 500, D4, 500, A4, 500, D5, 500, D4, 500, C4, 250, C4, 250, A3, 250, E4, 500, D4, 500, D4, 500, D4, 1000};
//HEDWIG'S THEME (HARRY POTTER)
//int notes[] = {B4, 500, E5, 750, G5, 250, FS5, 500, E5, 1000, B5, 500, A5, 1500, FS5, 1500, E5, 750, G5, 250, FS5, 500, DS5, 1000, F5, 500, B4, 2500, B4, 500, E5, 750, G5, 250, FS5, 500, E5, 1000, B5, 500, D6, 1000, CS6, 500, C6, 1000, GS5, 500, C6, 750, B5, 250, AS5, 500, AS4, 1000, G5, 500, E5, 2500, G5, 500, B5, 1000, G5, 500, B5, 1000, G5, 500, C6, 1000, B5, 500, AS5, 1000, FS5, 500, G5, 750, B5, 250, AS5, 500, AS4, 1000, B4, 500, B5, 2500, G5, 500, B5, 1000, G5, 500, B5, 1000, G5, 500, D6, 1000, CS6, 500, C6, 1000, GS5, 500, C6, 750, B5, 250, GS5, 500, AS4, 1000, G5, 500, E5, 2500};


enum POSITION {HOME, UP, DOWN, LEFT, RIGHT, OTHER};
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int buzzerPin = 13;
int randomNo = random(1, 5);
int score = 0;
int x = 0; 
int y = 0;
int i = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11,12);

int find_position (int x, int y) {
  if (HOME(x, y)) {
    return HOME;
  }
  else if (UP(x, y)) {
    return UP;
  }
  else if (DOWN (x, y)) {
    return DOWN;
  }
  else if (LEFT(x, y)) {
    return LEFT;
  }
  else if (RIGHT(x, y)) {
    return RIGHT;
  }
  else {
    return OTHER;
  }  
}

void display_function (int location) {
  switch (location) {
    case UP: {
      lcd.print("UP");
    }
    break;
    case DOWN: {
      lcd.print("DOWN");
    }
    break;
    case LEFT: {
      lcd.print("LEFT");
    }
    break;
    case RIGHT: {
      lcd.print("RIGHT");
    }
    break;
    case HOME: {
      lcd.print("HOME");
    }
    break;
    default: {
      lcd.print("OTHER");
    }
  }  
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void game() {
   if (randomNo == find_position(x, y)){
    tone(buzzerPin, notes[i], 0);
    delay(notes[i+1]);
    noTone(buzzerPin);
    randomNo = random(1, 5);
    score+=5;
    if (i < (sizeof(notes)/sizeof(int))) {
      i+=2;
    }
    else {
      i = 0;
      score = 0;
    }
  }
}

void display_screen() {
  lcd.clear();
  lcd.setCursor(0,0);
  display_function(randomNo);
  lcd.setCursor(0,1);
  lcd.print("Score: ");
  lcd.print(score); 

}

void input() {
  x = analogRead(X_pin);
  y = analogRead(Y_pin);
}
void loop() { 
  display_screen();    
  input();
  game();
}
