#include <avr/io.h>
#include <util/delay.h>

// Define the GPIO pins for the LEDs
#define LED1_PIN_NUMBER PB0
#define LED2_PIN_NUMBER PB1

// Function to configure GPIO pins as output for LEDs
void configureLEDs()
{
    DDRB |= (1 << LED1_PIN_NUMBER) | (1 << LED2_PIN_NUMBER); // Set LED pins as outputs
}

// Function to turn on an LED
void turnOnLED(uint8_t pin)
{
    PORTB |= (1 << pin); // Set the pin HIGH to turn on the LED
}

// Function to turn off an LED
void turnOffLED(uint8_t pin)
{
    PORTB &= ~(1 << pin); // Set the pin LOW to turn off the LED
}

// Function to toggle the state of an LED
void toggleLED(uint8_t pin)
{
    PORTB ^= (1 << pin); // Invert the state to toggle the LED
}

// Example usage
int main()
{
    // Configure the GPIO pins for the LEDs
    configureLEDs();
    
    // Turn on LED1
    turnOnLED(LED1_PIN_NUMBER);
    
    _delay_ms(1000); // Delay for 1 second
    
    // Turn off LED1
    turnOffLED(LED1_PIN_NUMBER);
    
    // Toggle LED2 in a loop
    while (1) {
        toggleLED(LED2_PIN_NUMBER);
        _delay_ms(500); // Delay for 0.5 seconds
    }
    
    return 0;
}
