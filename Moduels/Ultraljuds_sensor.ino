
//pin 12 and 11 are senders and recivers respectively

const int trigPin = 12;
const int echoPin = 11;
int trigdelay = 10;


//the long variable stores the travel time from the trig as a 32 bit number
//the distance int is used to store the distance in front of the sensor
long pingduration;
int distance;


void setup() {
  //in the set up we define trig pin as output and echo pin as a input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); //this code can be used to display the data

}

void loop() {
  //Make sure trigpin is clear. Then a signal is sent  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(trigdelay);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(trigdelay);
  digitalWrite(trigPin, LOW);

  //pingduration stores the travel time which is then used to calculate the distance
  //the disstance: d = t x v / 2 (since the sound bounces it actually traves twice as far)
  pingduration = pulseIn(echoPin, HIGH);
  distance = pingduration*0.034/2;

  //displays distance on serial monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  

  


  

  

}
