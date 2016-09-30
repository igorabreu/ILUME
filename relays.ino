
int RELAY[] = {2,3,4,5,6,7,8,9};
int value;

#define RELAY1  RELAY[0] 
#define RELAY2  RELAY[1] 
#define RELAY3  RELAY[2] 
#define RELAY4  RELAY[3] 
#define RELAY5  RELAY[4] 
#define RELAY6  RELAY[5] 
#define RELAY7  RELAY[6] 
#define RELAY8  RELAY[7] 

unsigned long previousMillis = 0; 
const long interval = 500;
                       
void setup(){    
  Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);  
  pinMode(RELAY2, OUTPUT);  
  pinMode(RELAY3, OUTPUT);  
  pinMode(RELAY4, OUTPUT); 
  pinMode(RELAY5, OUTPUT);  
  pinMode(RELAY6, OUTPUT);  
  pinMode(RELAY7, OUTPUT);  
  pinMode(RELAY8, OUTPUT);       
}

void loop(){
  blinkLamps();
}

void blinkLamps(){
while (Serial.available()){
 
   int value = Serial.read();

      if(value){
   /*   for(int i=0; i<8; i++){
      digitalWrite(RELAY[i], LOW); 
      digitalWrite(RELAY[i+2], LOW); 
      delay(50);
      digitalWrite(RELAY[i],HIGH);
      digitalWrite(RELAY[2],HIGH); */
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      for(int i=0; i<8; i++){
      digitalWrite(RELAY[i], LOW);
      delay(25);
      digitalWrite(RELAY[i], HIGH);
      delay(25);
      }
      }else{
      for(int i=0; i<8; i++){
      digitalWrite(RELAY[i], LOW);
        }
       }
    }

  }

}



