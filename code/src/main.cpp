#include <Arduino.h>
#define trigger_relay 0
#define output_soil 1
#define output_button 16

#define input_soil 28
#define input_button 15

unsigned int counter=0;


void setup() {
  // initialize the digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(trigger_relay, OUTPUT); 
  pinMode(output_soil, OUTPUT);
  pinMode(output_button, OUTPUT);

  pinMode(input_soil, INPUT);
  pinMode(input_button, INPUT_PULLDOWN);
  
}


void check_moisture_and_water(){
  digitalWrite(output_soil,HIGH); 

  delay(50); 
  float voltage=analogRead(input_soil)*3.3/1023;
  
  //automatic water if voltage low
  if (voltage<0.8){
    digitalWrite(trigger_relay,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(8000);
    
    Serial.print("Voltage in is: "); 
    Serial.println(voltage);
  }

  //no water
  else{
    digitalWrite(trigger_relay,LOW);
    digitalWrite(LED_BUILTIN,LOW);
    delay(1000);

    Serial.print("Voltage in is: "); 
    Serial.println(voltage);

  }

  digitalWrite(output_soil,LOW);

}


void loop() {

  digitalWrite(output_button,HIGH);  
  int manual_water = digitalRead(input_button);
  
  //automatic water
  if(counter%1800==0){
    check_moisture_and_water();
    counter=0;
  }

  //manual water with button press
  if(manual_water==1){
    digitalWrite(trigger_relay,HIGH);
    digitalWrite(LED_BUILTIN,HIGH);
    
    Serial.println("Manual watering: ");
    
  }
  else{
    counter++;

    digitalWrite(trigger_relay, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(output_button,LOW); 

    sleep_ms(2000);
  }

  
}
