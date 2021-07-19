/*
  AnalogReadSerial

  Reads an analog input on pin 0, prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogReadSerial
*/
char inByte = 0; 
char state = 'L';
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    if(inByte=='H'){digitalWrite(13,HIGH);state='H';}
    if(inByte=='L'){digitalWrite(13,LOW);state='L';}
  }
  Serial.print(state);
  Serial.print(",");
 
  Serial.print(map(analogRead(A0),0,1024,0,5000));
  Serial.print(",");

  Serial.print(map(analogRead(A1),0,1024,0,5000));
  Serial.print(",");

  Serial.print(map(analogRead(A2),0,1024,0,5000));
  Serial.print(",");

  Serial.print(map(analogRead(A3),0,1024,0,5000));
  Serial.println(",");
  
  delay(100);        // delay in between reads for stability
}
