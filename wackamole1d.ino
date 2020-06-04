//assign digital pins for LED and button
int pinkLED = 11;
int pinkButton = 10;

int redLED = 5;
int redButton = 4;

int greenLED = 13;
int greenButton = 12;

int yellowLED = 3;
int yellowButton = 2;

int buzzer = A5;

//declare and initialise global variables
bool stopGame = false;
int score = 0;
int strike = 0;
int points = 100;
double lifeSpan = 3000;
int getFaster = 10000;

unsigned long gameTime;
unsigned long updateGame;
unsigned long clockOne;
unsigned long clockTwo;

//game over tune
int numTones = 62;

int tones[] = {587, 784, 880, 988, 988, 988, 988, 988, 988, 988, 932, 988, 784,
               784, 784, 784, 784, 784, 784, 880, 988, 1047, 1047, 1319, 1319, 1319, 1319,
               1175, 1047, 988, 988, 988, 784, 880, 988, 1047, 1047, 1319, 1319, 1319, 1319,
               1175, 1047, 988, 988, 784, 784, 784, 784, 880, 988, 988, 988, 1047, 880, 880,
               880, 988, 784, 784, 784, 784
              };

//Serial Monitor display functions
void displayStrike() {
  Serial.println("");
  Serial.println("STRIKE ");
  Serial.print(strike);
  delay(2000);
}

void displayScore() {
  Serial.println("");
  Serial.print("SCORE: ");
  Serial.print(score);
}

class Mole {
  public:
    bool out;
    int moleButton;
    int moleLight;

    unsigned long exposedTime = millis();
    unsigned long escapeTime = exposedTime + lifeSpan;

    Mole(int button, int LED) {
      moleButton = button;
      moleLight = LED;
      out = false;
    }

    void changeExposedTime() {
      exposedTime = millis();
      escapeTime = exposedTime + lifeSpan;
    }

    bool isOut() {
      return out;
    }

    void hide() {
      out = false;
      lightSwitch();
    }

    void popOut() {
      out = true;
      lightSwitch();
    }

    void lightSwitch() {
      if (out) {
        digitalWrite(moleLight, HIGH);
      }
      if (!out) {
        digitalWrite(moleLight, LOW);
      }
    }

    void wasHit(bool buttonPressed) {
       //if pressed and mole is out
      if (out && buttonPressed) {
        out = false;
        tone(buzzer, 16.35, 1000);
        lightSwitch();
        //got rid of a delay here
        score += points;
        delay(150);
      }
      //if pressed but the mole has been out for too long
      if (out && gameTime > escapeTime) {
        strike++;
        tone(buzzer, 5, 2500);
        out = false;
        lightSwitch();
        displayStrike();
        delay(150);
      }
}
};

Mole pinkMole(pinkButton, pinkLED);
Mole greenMole(greenButton, greenLED);
Mole redMole(redButton, redLED);
Mole yellowMole(yellowButton, yellowLED);

void updateGameDifficulty() {
  if (gameTime > updateGame + getFaster) {
    lifeSpan *= 0.8;
    updateGame = millis();
    points += 25;
  }
  gameTime = millis();
}

//turn on LED at random
void randomMole() {
  int mole;
  randomSeed(analogRead(A3));
  mole = (int)random(0, 4);
  if (mole == 0) {
    if (!pinkMole.isOut()) {
      pinkMole.popOut();
      pinkMole.changeExposedTime();
    }
  }
  if (mole == 1) {
    if (!greenMole.isOut()) {
      greenMole.popOut();
      greenMole.changeExposedTime();
    }
  }
  if (mole == 2) {
    if (!redMole.isOut()) {
      redMole.popOut();
      redMole.changeExposedTime();
    }
  }
  if (mole == 3) {
    if (!yellowMole.isOut()) {
      yellowMole.popOut();
      yellowMole.changeExposedTime();
    }
  }
}

void flashMoles() {
  pinkMole.popOut();
  greenMole.popOut();
  redMole.popOut();
  yellowMole.popOut();
  delay(1000);
  pinkMole.hide();
  greenMole.hide();
  redMole.hide();
  yellowMole.hide();
  delay(1000);
}

void playtune() {
  for (int i = 0; i < numTones; i++) {
    tone(buzzer, tones[i]);
    delay(350);
  }
  noTone(buzzer);
}

void endGame() {
    flashMoles();
    Serial.println("");
    Serial.println(" GAME OVER!!!!");
    displayScore();
    playtune();
    flashMoles();
    Serial.println("");
    Serial.println(" GAME OVER!!!!");
    displayScore();
    delay(2000);
    stopGame = true;
}

void resetGlobalVar() {
  score = 0;
  strike = 0;
  lifeSpan = 3000;
  points = 100;
  getFaster = 10000;
  stopGame = false;
  gameTime = millis();
  updateGame = millis();
  clockOne = millis();
  clockTwo = millis();
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pinkButton, INPUT_PULLUP);
  pinMode(pinkLED, OUTPUT);

  pinMode(greenButton, INPUT_PULLUP);
  pinMode(greenLED, OUTPUT);

  pinMode(redButton, INPUT_PULLUP);
  pinMode(redLED, OUTPUT);

  pinMode(yellowButton, INPUT_PULLUP);
  pinMode(yellowLED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Welcome to the Game.");

  gameTime = millis();
  updateGame = millis();
  clockOne = millis();
  clockTwo = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
    if (!stopGame)
    {
      displayScore();
      bool pinkB = (digitalRead(pinkButton) == 0);
      bool greenB = (digitalRead(greenButton) == 0);
      bool yellowB = (digitalRead(yellowButton) == 0);
      bool redB = (digitalRead(redButton) == 0);
  
      if (clockOne > clockTwo + 2500) {
        randomMole();
        clockTwo = millis();
      }
  
      pinkMole.wasHit(pinkB);
      greenMole.wasHit(greenB);
      yellowMole.wasHit(yellowB);
      redMole.wasHit(redB);
  
      updateGameDifficulty();
      clockOne = millis();
    }
    //game over condition
    if(strike==5)
    {
    endGame();
    resetGlobalVar();
    }
}
