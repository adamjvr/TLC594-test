#include <Adafruit_TLC5947.h>

// Pin configuration
#define DATA_PIN 6  // Arduino pin connected to TLC5947 SDI (Serial Data In)
#define CLOCK_PIN 5 // Arduino pin connected to TLC5947 SCK (Serial Clock)
#define LATCH_PIN 4 // Arduino pin connected to TLC5947 XLAT (LATCH)

// Number of TLC5947 devices daisy-chained
#define NUM_TLC5947 1 // Set to the number of devices you have connected

// Create an instance of the Adafruit_TLC5947 library
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, CLOCK_PIN, DATA_PIN, LATCH_PIN);

void setup() {
  // Initialize the TLC5947 library
  tlc.begin();
  
  // Set the maximum brightness (0-4095)
  tlc.setPWM(0, 4095); // Set maximum brightness for all channels
}

void loop() {
  // Use the setPWM function to set the PWM values for each channel.
  // Channel numbers range from 0 to 23.
  // Duty cycle values range from 0 (off) to 4095 (full brightness).

  // Loop through all 24 channels
  for (int channel = 0; channel < 24; channel++) {
    // Generate a random duty cycle value between 0 and 4095
    int dutyCycle = random(0, 4096);
    
    // Set the PWM value for the current channel
    tlc.setPWM(channel, dutyCycle);
  }

  // Update the display to show the new PWM values
  tlc.write();

  // Delay for 1 second before updating the PWM values again
  delay(1000);
}
