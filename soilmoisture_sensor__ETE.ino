#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C screen(0x27 , 16 , 2);

 int inpt =A3;
 int r =8;
 int y =9;
 int b =10;
 int g =11;
 int m =2;


void setup() {
  pinMode(inpt ,INPUT);
  pinMode(r ,OUTPUT);
  pinMode(y ,OUTPUT);
  pinMode(b ,OUTPUT);
  pinMode(g ,OUTPUT);
  pinMode(m , OUTPUT);
  
  }

void loop() {
   Serial.begin(9600);
   screen.init();
   screen.backlight();
  int digital = analogRead(inpt);
  float vtg = digital*(5.0/1023.0);
  float percentage =((vtg* 100)/5 );

Serial.print("digital input of soil moisture sensor =");
Serial.println(digital);
Serial.print("voltage of soil moisture sensor =");
Serial.println(vtg);
Serial.print("total purcentage of moisture present in soil =");
Serial.println(percentage);
Serial.println();


if(percentage <= 5.0){
    digitalWrite(r ,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
    screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
    screen.setCursor(3,0);
    screen.print("turning on");
    screen.setCursor(3,1);
    screen.print("the motor");
    digitalWrite(m ,HIGH);
    delay(200);
 }
  else if((percentage <= 25.0) &&(percentage >= 5.0)){
    digitalWrite(r ,HIGH);
    digitalWrite(y,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
     screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
 
          }
          
else if((percentage > 25.0) && (percentage<= 50.0)){
   digitalWrite(y ,HIGH);
   digitalWrite(r,LOW);
   digitalWrite(g,LOW);
   digitalWrite(b,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
     screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
      }

  else if((percentage > 50.0) && (percentage<= 75.0)){
   digitalWrite(b ,HIGH);
   digitalWrite(r,LOW);
   digitalWrite(y,LOW);
   digitalWrite(g,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
     screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
    }
  
 else if((percentage > 75.0) && (percentage<= 95.0)){
   digitalWrite(g ,HIGH);
   digitalWrite(y,LOW);
   digitalWrite(r,LOW);
   digitalWrite(b,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
     screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
        
  }
  
      else if((percentage > 95.0)&&(percentage<97)){
   digitalWrite(g ,HIGH);
   digitalWrite(y,LOW);
   digitalWrite(r,LOW);
   digitalWrite(b,LOW);
    screen.print("moisture present");
   screen.setCursor(0,1);
    screen.print("in soil is = ");
    screen.setCursor(13,1);
    screen.print(percentage);
    screen.clear();
    screen.print(" please turn off");
    screen.setCursor(0,1);
    screen.print("the motor");
    delay(200);
    screen.clear();
        
  }

  else if(percentage >= 98.0){
    digitalWrite(g ,HIGH);
    digitalWrite(r,LOW);
    digitalWrite(y,LOW);
    digitalWrite(b,LOW);
    digitalWrite(m,LOW);
    screen.print("moisture present");
    screen.setCursor(0,1);
    screen.print("in soil is = ");
    screen.setCursor(13,1);
    screen.print(percentage);
    delay(200);
    screen.clear();
    screen.setCursor(1,0);
    screen.print(" turning off");
    screen.setCursor(3,1);
    screen.print("the motor");
    delay(200);
    screen.clear();
          
  }
  
      

}
