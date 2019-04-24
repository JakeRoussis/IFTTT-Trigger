// Declare pins/variables
int photoresistor = A5;
int sunlight;
bool isSun = false;
bool prevState = false;

void setup() {
  pinMode(photoresistor, INPUT);
  Particle.variable("sunlight", sunlight);
      Serial.begin(9600);


}

void loop() {
    sunlight = analogRead(photoresistor);
    
    if (sunlight > 35)
    {
        isSun = true;
    } else {
        isSun = false;
    }
    
    if (isSun != prevState)
    {
        prevState = isSun;
        
        Particle.publish("isSun", String(isSun), PRIVATE);
    }
    
    Particle.publish("sunlight", String(sunlight), PRIVATE);

    delay(2000);
}

