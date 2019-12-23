const int analogInPin1 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin2 = A1;  // Analog input pin that the potentiometer is attached to
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 11; // Pin  7 of L293
const int motorPin4  = 12;  // Pin  2 of L293 
int sensorValue1=0;
int sensorValue2=0;
int sensorComp1[50];
int sensorComp2[50];
int x = 0;
int avg1 = 0;
int avg2 = 0;
int whiteCount = 0;

void setup() {
Serial.begin(9600); //sets serial port for communication
pinMode(motorPin1, OUTPUT);
pinMode(10, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  if (x == 50){
    for (int j = 0; j < 50; j++){
      avg1 += sensorComp1[j];
      avg2 += sensorComp2[j];
    }

    avg1 = avg1/50;
    avg2 = avg2/50;
  }
  
  digitalWrite(10, HIGH);
  sensorValue1 = analogRead(analogInPin1); 
  sensorValue2 = analogRead(analogInPin2);

  if (x<50){
    sensorComp1[x] = sensorValue1;
    sensorComp2[x] = sensorValue2;
    x++;
  }
  
Serial.println(avg1); //prints the values coming from the sensor on the screen
Serial.println(sensorValue1); //prints the values coming from the sensor on the screen
Serial.println(avg2); //prints the values coming from the sensor on the screen
Serial.println(sensorValue2); //prints the values coming from the sensor on the screen
//delay (20);
  if (((avg1-10)<sensorValue1 && sensorValue1<(avg1+10)) &&((avg2-60)<sensorValue2 && sensorValue2<(avg2+20)))
  {
    whiteCount==0;
    Serial.println("LEFT");
     digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
    delay(125);
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  else if (avg1==0 && avg2==0)
  {
    Serial.println("STOP"); 
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
  else if (sensorValue1<avg1&&(((avg2-20)<sensorValue2 && sensorValue2<(avg2+20))))
  {
    whiteCount++;
//    if (whiteCount <2){
      Serial.println("RIGHT"); 
       digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(125);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        
      } 
      else {
        Serial.println("RIGHT90"); 
       digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(500);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        whiteCount==0;
      }
    }
  delay(50);
}
