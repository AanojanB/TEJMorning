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

  digitalWrite(red, HIGH);
  digitalWrite(buzzer, LOW);
  analogWrite(r,255);  
  analogWrite(g,128);
  analogWrite(b,0);
}

void loop(){

  
  if(digitalRead(button) == HIGH){
   delay(15);
     if(digitalRead(button) == HIGH){
     changeLights();
     delay(15000);
   }
  }


  
  }

void changeLights() {

  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH);
  analogWrite(r,255);  
  analogWrite(g,128);
  analogWrite(b,0);
  delay(3000);

  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  analogWrite(r,130);  
  analogWrite(g,130);
  analogWrite(b, 130);
  digitalWrite(buzzer, HIGH);
  delay(5000);

  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  analogWrite(r,255);  
  analogWrite(g,128);
  analogWrite(b,0);
  digitalWrite(buzzer, LOW);
  delay(2000);

  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
 

  delay(3000);

}
