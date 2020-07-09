int SPDL = 4;     //speed vary PWM INPUT for Forward & Backward
int fb = 5;      //Forward , Backward Input
int lr = 6;      //Left , Right Input

int spdr = 6;    //speed vary PWM INPUT for  Left and Right
int BRKR = 5;    //Brk pin


void setup() {
  Serial.begin(9600);
  pinMode (fb,INPUT);
  pinMode (lr,INPUT);                  //declaration of input pins
  pinMode (spd,INPUT);

  
  pinMode(11,OUTPUT);                  //Output Pins
pinMode(12,OUTPUT);
  }
void loop()
{

  long duration1,duration2, duration3; 
  duration1 = pulseIn(fb, HIGH);
  duration2 = pulseIn(lr, HIGH);    // Reads the input duration from the RC Reciver module using pulseIn() and stores in variable
  duration3 = pulseIn(spd, HIGH);
  
   duration3 = constrain (duration3, 1000, 2000);        // Limits the speed input ( PWM in ) to be between 1000 and 2000
   duration3 = map(duration3, 1000, 2000, 0, 255);       //changes the variation of 1000 - 2000  into 0 - 255 so that it can used for analog write()       
  
  analogWrite(SPDL, duration3);   //The set speed is fed into the motor driver PWM pin
  analogWrite(spdr, duration3); 
  
  if(duration1<800 && duration2<800)
   
   {
    Serial.print("STOP");     
   }
 
  else if (duration1>1650 && duration2<1650 && duration2>1350)
  {
    Serial.print("FORWARD");  
  }
  else if (duration1<1350  && duration2<1650 && duration2>1350)
  {
    Serial.print("BACKWARD");    
  }
  else if (duration2>1650  && duration1<1650 && duration1>1350)
  {
    Serial.print("LEFT TURN"); 
  }
  else if (duration2<1350 && duration1<1650 && duration1>1350)
  {   
    Serial.print("RIGHT TURN");
  }

  else if (duration1>1650 && duration2>1650)
  {
    Serial.print("FORWARD_LEFT");
  }
  else if (duration1>1650 && duration2<1350)
  {
    Serial.print("FORWARD_RIGHT"); 
  }
  else if (duration1<1350  && duration2>1650)
  {
    Serial.print("BACK_LEFT");
  }
  else if (duration1<1350 && duration2<1350)
  {
    Serial.print("BACK_RIGHT"); 
  }
  else
  {
    Serial.print("STOP");
     Serial.print("   ");
  }

  Serial.print("duration1=");
  Serial.print(duration1);
  Serial.print("   ");
  Serial.print("duration2=");
  Serial.print(duration2);
  Serial.print("   ");
  Serial.print("duration3=");
  Serial.println(duration3);
  
}


