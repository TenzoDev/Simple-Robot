/*---------------------Simple ROBOT-------------------
 *-------------Control robot using bluetooth---------- 

 *------------------------TENZO-----------------------
*/

int IN1 = 4; 
int IN2 = 5; 
int IN3 = 6; 
int IN4 = 7;
int v = 255;
int x = 'S';

void setup() { 
Serial.begin(9600);   // Default communication rate of the Bluetooth module
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
} 

void loop() {
   
    // Read the incoming data from the Android application
if(Serial.available()>0)  // Ckeck for data Recieved
   { 
      x = Serial.read();  // Read data
   }

if(x=='S'){ // Stop
    Serial.println(x);
analogWrite(IN4, 0); 
analogWrite(IN2, 0); 
analogWrite(IN3, 0); 
analogWrite(IN1, 0); 
}

if(x=='F'){ // Forward
  Serial.println(x); 
analogWrite(IN1, v); 
analogWrite(IN2, 0);
analogWrite(IN3, v); 
analogWrite(IN4, 0); 

}

if(x=='B'){ // Reverse
    Serial.println(x);
analogWrite(IN1, 0); 
analogWrite(IN2, v);
analogWrite(IN3, 0); 
analogWrite(IN4, v); 
}

if(x=='R'){ // right
    Serial.println(x);
analogWrite(IN1, v); 
analogWrite(IN2, 0);
analogWrite(IN3, 0); 
analogWrite(IN4, 0); // we can use (IN4, v)

}

if(x=='L'){ // left
    Serial.println(x);
analogWrite(IN1, 0); 
analogWrite(IN2, 0);  // we can use (IN2, v)
analogWrite(IN3, v); 
analogWrite(IN4, 0); 

} 

}
