#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int red = 10;
int yellow =   9;
int green = 8 ;

int buzzer = 13;

int button = 6;

int b = A0;
int g = A1;
int r = A2;

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

void setup() {

  lcd.begin(16, 2);

  lcd.createChar(0, Walker);

  
  lcd.createChar(1, Hand);

  lcd.clear();

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
  

  analogWrite(r,255);  
  analogWrite(g,127);
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

  for(int i = 0; i < 10; i++){


  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(200);
  }


  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  analogWrite(r,200);  
  analogWrite(g,200);
  analogWrite(b, 200);
  
  lcd.setCursor(0,1);
  lcd.write(byte(0));

  delay(5000);

  
  
   for(int i = 10; i > 0; i--){

    for(int j = 10; j > 0; j--){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(i);
      lcd.setCursor(0,1);
      lcd.write(byte(1));
      delay(40);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(i);
      delay(60);
    
    }
   }
  
  

  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  analogWrite(r,255);  
  analogWrite(g,127);
  analogWrite(b,0);
    digitalWrite(buzzer, LOW);
    lcd.clear();
  delay(2000);


  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  lcd.clear();
    lcd.setCursor(0,1);
  lcd.write(byte(1));


}
