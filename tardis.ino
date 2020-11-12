/**
* This code was made to recreate the light (pulse) effect that the TARDIS from Doctor Who makes when traveling through time.
* You can connect as many LED diodes as you wish to the same PWM pin and they will pulse in sync.
* 
* Created in 2020 by https://github.com/dennieb/
*/

int pwmPin = 11;            // The PWM pin the LED is attached to, in this example pin 11. (Note: Not all pins work! If the code does nothing, it's probably not a PWM pin!!).
int pulseCycle = 5;         // How many times the pulse cycle plays in between loops.
int restPeriod = 30000;      // How many seconds the light stays on in between the next pulse cycle. 1000 = 1 second.

int brightness = 0;         // NO NEED TO CHANGE THIS VARIABLE. This declares the brightness at which the loop starts, which is 0 by default.
int fadeAmount = 5;         // NO NEED TO CHANGE THIS VARIABLE. This is the increment in which the LED fades. This is 5 by default.

void setup() {
  pinMode(pwmPin, OUTPUT);
}

void loop() {   
  
    //This makes the LEDs pulse x amount of times, where x is the amount in variable pulseCycle.
    for (int i = 0; i < pulseCycle;) {
      analogWrite(pwmPin, brightness);
    
      brightness = brightness + fadeAmount;

      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        if(brightness <= 0){
          i++;
        }
      }
      delay(18);
    }  

    //Resets the variables to their default values in preparation for the last half pulse. 
      brightness = 0;
      fadeAmount = 5;

    //Runs through half a pulse cycle to make sure the LEDs are transfered smoothly from an OFF state to an ON state. Without this, the LEDs might display a sudden "glitchy" jump from being OFF to full brightness ON.
    for (int i = 0; i < 1;) {
      analogWrite(pwmPin, brightness);
    
      brightness = brightness + fadeAmount;

      if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
        i++;
      }
      delay(18);
    }  

    //Turns the LEDs to full brightness for x amount of time after the pulse cycle ends, where x is the amount in variable restPeriod.
      analogWrite(pwmPin, 255);
      delay(restPeriod);
}
