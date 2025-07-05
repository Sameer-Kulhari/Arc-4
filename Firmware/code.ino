//here are pin configurations 
int button1 = 0;
int button2 = 1;
int button3 = 2;
int submitButton = 3;

int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

int guess1;
int guess2;
int guess3;

int code1;
int code2;
int code3;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(submitButton, INPUT_PULLUP);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  randomSeed(analogRead(0));
  code1 = random(2);
  code2 = random(2);
  code3 = random(2);
}

void loop() {
  //this part of code turn on led if button is pressed 
  if (digitalRead(button1) == LOW) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }

  if (digitalRead(button2) == LOW) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  if (digitalRead(button3) == LOW) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
  //this part checks if button is pressed if pressed it will go in a loop which does nothing and when it is relased it execute the rest of the code.So,basically this part execute code for button press and release
  if (digitalRead(submitButton) == LOW) {
    delay(50);
    while (digitalRead(submitButton) == LOW) {
      
    }
  //here is the code for checking guess it assignes the current button state to guess1,guess2,guess3
    if (digitalRead(button1) == LOW) {
      guess1 = 1;
    } else {
      guess1 = 0;
    }

    if (digitalRead(button2) == LOW) {
      guess2 = 1;
    } else {
      guess2 = 0;
    }

    if (digitalRead(button3) == LOW) {
      guess3 = 1;
    } else {
      guess3 = 0;
    }
  //if all guesses are correct it turn on all the lights for 2 sec
    if (guess1 == code1 && guess2 == code2 && guess3 == code3) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      delay(2000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      code1 = random(2);
      code2 = random(2);
      code3 = random(2);
    } else { // if guess is wrong it blinks all leds 3 times with 0.2 sec delay between them
      for (int i = 0; i < 3; i++) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
        delay(200);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        delay(200);
      }
    }
  }
}
//End XD
//Made by : Sameer
//Github  : https://github.com/Sameer-Kulhari/