
byte ledr = 11;                   // which pin LED is connected to
byte ledg = 10;
byte ledb = 9;

byte intensity = 0;             // led brightness
byte increment = 1;             // brightness increase on each loop
byte timer = 60;                // duration of each loop
float flashtimer = 120;         // flash duration
byte nflash = 1;                // number of flash

void setup() {
  pinMode(ledr, OUTPUT);
  analogWrite(ledr,0);
  pinMode(ledg, OUTPUT);
  analogWrite(ledg,0);
  pinMode(ledb, OUTPUT);
  analogWrite(ledb,0);
//  flashtimer = (timer * 0.9);
}

void loop () {


  intensity = intensity + increment;

  analogWrite(ledr,intensity);
  analogWrite(ledg,intensity);
  analogWrite(ledb,intensity);
  if (intensity >= 30) {
    flareEffect(ledr, ledg, ledb, nflash, flashtimer);
    increment = -increment;
  }  
  if (intensity <= 0) {
    delay(2000);
    increment = -increment;
  }
  if (intensity >= 30) {
    
  }
  delay(timer);

}

void flareEffect (byte ledr, byte ledg, byte ledb, byte nflash, float flashtimer) {
     for (int flareCount = 0; flareCount < nflash; flareCount++) {
     analogWrite(ledr, 30);
     analogWrite(ledg,30);
     analogWrite(ledb,30);
     delay(40);
     analogWrite(ledr,255);
     analogWrite(ledg,255);
     analogWrite(ledb,255);
     delay(flashtimer);  
  }
}
