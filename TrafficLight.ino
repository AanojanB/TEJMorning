int red = 10;
int yellow =   9;
int green = 8 ;

int buzzer = 13;

int button = 12;

int b = 7;
int g = 6;
int r = 5;


void setup() {

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button, INPUT);

  pinMode(r,OUTPUT);
  pinMode(r,OUTPUT);
    pinMode(r,OUTPUT);

  digitalWrite(green, HIGH);
  digitalWrite(buzzer, HIGH);
    analogWrite(r,200);  
  analogWrite(g,200);
  analogWrite(b,200);

}

void loop(){

  
  if(digitalRead(button) == HIGH){
   delay(15);
     if(digitalRead(button) == HIGH){
     changeLights();
     //delay(15000);
   }
  }


  
  }

void changeLights() {

  digitalWrite(green, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(yellow, HIGH);
  analogWrite(r,255);  
  analogWrite(g,128);
  analogWrite(b,0);
  delay(3000);

  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
  delay(5000);

  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);
  delay(2000);

  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  analogWrite(r,200);  
  analogWrite(g,200);
  analogWrite(b, 200);
  digitalWrite(buzzer, HIGH);
  //delay(3000);

}
