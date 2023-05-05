#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int red = 10;
int yellow =   9;
int green = 8 ;


int buzzer = 13;

int button = 6;

int r = A3;
int g = A4;
int b = A5;

boolean buzzerOn;


byte Walker[8] =
{
0b01110,
0b01110,
0b00100,
0b01111,
0b10100,
0b00110,
0b01001,
0b10001
};


byte Hand[8] =
{
0b00010,
0b00111,
0b10111,
0b11111,
0b11111,
0b01111,
0b00111,
0b00000
};


byte Arrow[8] =
{
0b00000,
0b00000,
0b00010,
0b11111,
0b00010,
0b00000,
0b00000,
0b00000
};

void setup() {

  lcd.begin(16, 2);

  lcd.createChar(0, Walker);

  
  lcd.createChar(1, Hand);

    lcd.createChar(2, Arrow);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write(byte(1));
  

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button, INPUT);

  pinMode(r,OUTPUT);
  pinMode(r,OUTPUT);
  pinMode(r,OUTPUT);
    
  buzzerOn = false;

  digitalWrite(red, HIGH);
  

  analogWrite(r,0);  
  analogWrite(g,0);
  analogWrite(b,0);
  
  Serial.begin(9600);

}

void loop(){

  

  Serial.println(buzzerOn);


  if(digitalRead(button) == HIGH){
   delay(15);
     if(digitalRead(button) == HIGH){
     changeLights();
     //delay(15000);
   }
  }

}

void changeLights() {
   


  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  analogWrite(r,0);  
  analogWrite(g,255);
  analogWrite(b,0);
  
  lcd.setCursor(0,1);
  lcd.write(byte(2));

  delay(5000);

  analogWrite(r,200);  
  analogWrite(g,255);
  analogWrite(b,0);


  delay(5000);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write(byte(0));
  analogWrite(r,0);  
  analogWrite(g,0);
  analogWrite(b,0);
  delay(10000);

   for(int i = 10; i > 0; i--){
  digitalWrite(buzzer, HIGH);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write(byte(1));
  lcd.setCursor(0,0);

  lcd.print(i);
  delay(600);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(i);
  digitalWrite(buzzer, LOW);
  delay(400);
  }
  
  

  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  analogWrite(r,0);  
  analogWrite(g,0);
  analogWrite(b,0);
    digitalWrite(buzzer, LOW);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.write(byte(1));
  
  delay(2000);


  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  lcd.clear();
    lcd.setCursor(0,1);
  lcd.write(byte(1));


}
