int red = 10;
int yellow =   9;
int green = 8 ;



int button = 12;




void setup() {

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);



  pinMode(button, INPUT);

  digitalWrite(green, HIGH);
  

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
  digitalWrite(yellow, HIGH);
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
  //delay(3000);

}
