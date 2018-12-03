const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
#define analog0 0
#define ledR 9
#define ledG 11
#define ledB 10

int mode = 0 ;
int analogvalue = 0;
int buttonState ; 

void setup() {
 Serial.begin(9600) ;
 Serial.println("Program Start") ;
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {  
  buttonState = digitalRead(buttonPin);
  analogvalue = analogRead(analog0) ;   
  Serial.println(analogvalue);
  
  if (buttonState == LOW) {
     mode++;   
    if(mode > 2){
    mode = 0;   
   }  
   delay(300);    
   }  
   
    if(mode == 0){    
    analogWrite(ledB,LOW);  
    analogWrite(ledR,HIGH);   
    analogWrite(ledR,analogvalue/4);  
              }      
    if(mode == 1){  
    analogWrite(ledR,LOW);     
    analogWrite(ledG,HIGH); 
    analogWrite(ledG,analogvalue/4); 
           }
    if(mode == 2){     
    analogWrite(ledG,LOW);     
    analogWrite(ledB,HIGH);
    analogWrite(ledB,analogvalue/4);  
      }
            
}
