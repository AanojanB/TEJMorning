int red = 10;
int yellow =   9;
int green = 8 ;
int button = 12;



void setup() {

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  pinMode(button, INPUT);

  digitalWrite(green,HIGH);

  Serial.begin(9600);
  

}

void loop(){
  
 Serial.println(digitalRead(button));
  digitalWrite(green,digitalRead(button));
}
    

  
