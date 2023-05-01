int red = 10;
int yellow =   9;
int green = 8 ;

int buzzer = 13;

int button = 12;

int b = 7;
int g = 6;
int r = 5;

boolean buzzerOn;

void setup() {

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
  analogWrite(g,128);
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
  analogWrite(r,200);  
  analogWrite(g,200);
  analogWrite(b, 200);
  for(int i = 0; i < 10; i++){

  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(buzzer, LOW);
  delay(200);
  }
  

  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  analogWrite(r,255);  
  analogWrite(g,128);
  analogWrite(b,0);
    digitalWrite(buzzer, LOW);
  delay(2000);


  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);


}
