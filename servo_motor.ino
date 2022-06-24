void my_servo(byte number_pin,byte degree);
const int Servo_pin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(Servo_pin, OUTPUT);
}
void loop() 
{
  my_servo(Servo_pin,0);
  delay(1000);
  my_servo(Servo_pin,90);
  delay(1000);
  my_servo(Servo_pin,180);
  delay(1000);
}
void my_servo(byte number_pin,byte degree)
{
  float low,high;
  if (degree==0)
  {
     high=500;
     low=20000-high;
  }  
  else if (degree==90)
  {
     high=1444.8;
     low=20000-high;
  }
  else if (degree==180)
  {
     high=2389.5;
     low=20000-high;
  } 
  for (int i = 0; i < 50; i++)
  {
    digitalWrite(number_pin, HIGH);
    delayMicroseconds(high);
    digitalWrite(number_pin, LOW);
    delayMicroseconds(low);
  }
  }
