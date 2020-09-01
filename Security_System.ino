#include<LiquidCrystal.h>

LiquidCrystal lcd(33,31,29,27,25,23);

const int red = 10, green = 9, blue = 8, buz = 36;
int count = 0;
String pas = "alpha", ext = "close"; //input (system on and exit code)

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buz, OUTPUT);

  lcd.begin(16, 2);
  Serial3.begin(9600);

  digitalWrite(buz, 1);
  lcd.setCursor(1, 0);

  lcd.print("Mahadi Hassan");
  lcd.setCursor(4, 1);
  lcd.print("MITHUN");
  delay(1000);

  digitalWrite(buz, 0);

  lcd.noDisplay();
  delay(200);
  lcd.display();

}

void loop() {

  String s = "";
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Enter Command:");
  lcd.setCursor(0, 1);
  lcd.print(">> ");

  lcd.cursor();
  delay(500);
  lcd.noCursor();
  delay(500);

  while (Serial3.available()) {
    s +=  (char)Serial3.read();
    delay(50);
    count = 0;
  }


  if (s != pas && s != "") {
    lcd.print(s);
    Serial3.println(s);
    digitalWrite(green, 1);
    digitalWrite(buz, 1);
    delay(200);

    digitalWrite(buz, 0);
    delay(1500);
    digitalWrite(blue, 0);
    digitalWrite(green, 0);
  }

  if (s != "") {
    lcd.clear();
    digitalWrite(blue, 0);

    if (s == pas) {

      digitalWrite(blue, 1);
      digitalWrite(green, 1);
      digitalWrite(buz, 1);
      delay(200);

      lcd.setCursor(0, 0);
      lcd.print("Enter Command:");
      lcd.setCursor(0, 1);
      lcd.print(">> ******");

      digitalWrite(buz, 0);
      delay(2000);
      digitalWrite(blue, 0);
      digitalWrite(green, 0);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Command Accecpt");
      lcd.setCursor(3, 1);
      lcd.print("welcome");


      digitalWrite(buz, 1);
      digitalWrite(green, 1);
      delay(700);
      for (int i = 0; i < 3; i++) {
        digitalWrite(buz, 0);
        digitalWrite(green, 0);
        lcd.noDisplay();
        delay(500);

        digitalWrite(buz, 1);
        digitalWrite(green, 1);
        lcd.display();
        delay(500);
      }
      digitalWrite(buz, 0);
      digitalWrite(green, 0);
      delay(500);
      digitalWrite(green, 1);
      lcd.clear();

      while (s != ext) {
        lcd.setCursor(0, 0);
        lcd.print("Your System");
        lcd.setCursor(0, 1);
        lcd.print("is on: ");
        delay(100);


        s = "";
        while (Serial3.available()) {
          s +=  (char)Serial3.read();
          delay(50);
          count = 0;
        }

        if (s != "") {

          if (s == ext) {
            digitalWrite(blue, 1);
            digitalWrite(buz, 1);
            lcd.print("log off...");
            delay(1000);
            digitalWrite(buz, 0);
            delay(200);
            digitalWrite(blue, 0);
          }


          //-------------------------------      input Section



          
          //else if (input Function)


          else {
            digitalWrite(blue, 1);
            digitalWrite(buz, 1);
            lcd.print("incorrect");
            lcd.setCursor(12, 0);
            lcd.print("-x-");
            delay(1000);
            lcd.clear();
            digitalWrite(buz, 0);
            digitalWrite(blue, 0);
          }

        }

        //dim light
        if (count > 40) {
          analogWrite(green, 30);
        }
        else {
          digitalWrite(green, 1);
        }
        count++;

      }
      digitalWrite(green, 0);
      digitalWrite(buz, 1);
      delay(700);
      digitalWrite(buz, 0);
      digitalWrite(green, 0);
      lcd.display();
    }

    else {
      lcd.noDisplay();
      delay(200);
      lcd.display();
      lcd.setCursor(0, 0);
      lcd.print("Access Denied !!");
      lcd.setCursor(4, 1);
      lcd.print("error");


      for (int i = 0; i < 5; i++) {
        digitalWrite(buz, 1);
        digitalWrite(red, 1);
        delay(150);
        digitalWrite(red, 0);
        digitalWrite(buz, 0);
        delay(150);
      }
      lcd.noDisplay();
      digitalWrite(buz, 1);
      delay(500);
      lcd.display();
      digitalWrite(buz, 0);
    }
  }

  //dim light
  if (count > 4) {
    analogWrite(blue, 30);
  }
  else {
    digitalWrite(blue, 1);
  }
  count++;
}
