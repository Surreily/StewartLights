# Stewart's Lighting

This is a simple Arduino project for controlling Adafruit NeoPixel strings. Although it contains everything you need (aside from hardware) to get the lights lit up, you can also add your own patterns (see the documentation below).

## Hardware

In order to use this program, you will need:

* An Arduino or compatible ATMEGA/ATTINY microcontroller.
* A NeoPixel strip (along with any relevant components).
* A button (along with pull-up or pull-down resistor).
* A power supply.
* (Optional) A project box.

As the project is simple, you should not have much trouble getting everything connected correctly. I recommend testing the lights with the NeoPixel's StrandTest sketch before connecting the button.

## Software

The string length, pins, and other parameters are defined in *Settings.h*.

* `STRIP_PIN` and `BUTTON_PIN` determine which pins on the microcontroller are used for the NeoPixel strip and the button.
* `STRIP_LENGTH` is the number of NeoPixels being driven.
* `STRIP_BRIGHTNESS` is the brightness of each NeoPixel (up to a maximum of 100).
* `DELAY_PERIOD` is the length of time (in milliseconds) that the program waits between loop iterations.
* `MINIMUM_BUTTON_CYCLES` is the number of loop iterations that the button needs to wait until being activated again (to prevent bouncing).

### Modifying Pattern Sequence

The pattern sequence is defined in the standard Arduino `loop` function. Inside here, each individual pattern function is called. You can call the same pattern function multiple times with different parameters.

    void loop() {
        staticPattern(strip, 0);
        rainbowPattern(strip, 220);
        ...
    }

Once the final pattern is skipped, the program resumes from the first pattern.

## Adding Patterns

You can define your own patterns by creating a header file (which includes the pattern prototype) and a file that contains the actual code that runs. 

In this documentation, a 'tick' is a single iteration of a pattern - similar to a 'frame' of animation. The `tick` function delays the program before checking the button's state and returning true if it is pressed.

### RGB Struct

The *core.h* file defines a struct that should be used when working with RGB values. It is defined as follows:

    struct RGB {
        byte r;
        byte g;
        byte b;
    };

When passing a color to the Adafruit NeoPixel library, you must pass the individual RGB values:

    RGB color = {255, 128, 0};
    pixels->setPixelColor(i, color.r, color.g, color.b);

### The Header File

Your header file should include the Adafruit NeoPixel library and contain one prototype for your pattern loop function. The prototype should take an `Adafruit_NeoPixel*` parameter (it is needed to manipulate the LED strip). Don't forget to add header guards and include the Adafruit NeoPixel library!

    // Prototype for pattern loop function
    void ExamplePatternLoop(Adafruit_NeoPixel* strip, int col);

### The Code File

Your code file should implement the header you created. The function should include a loop that continues until the `tick` function returns true (indicating the button has been pressed).

    void examplePatternLoop(Adafruit_NeoPixel* strip, int col) {
    
        // Do something on the first iteration only

        while (!tick()) {
            // Do something on every loop until the button is pressed again
        }

    }

Any code that executes once per pattern (for example, initializing the LEDs to a specific set of colors) should be put before the loop. Anything that is required to be run on every tick should be placed inside the loop. If a standard while loop (as shown above) is used, the code inside the loop will not be run for the pattern's first tick. Consider using a do-while loop if this is a problem.

### Helper Functions

Helper functions are defined inside *Core.h* and *Core.cpp*. If you intend to use any of these functons, you will need to include *Core.h*.

* `uint32_t getColor(int color)` *Deprecated* - Converts the given color integer (from 0 to 255) into a 'packed' RGB value that can be used in the Adafruit NeoPixel strip object's `setPixelColor` function in place of individual red, green, and blue values.

* `RGB getWheelColor(int pos)` - Converts the given color integer (from 0 to 255) into an RGB type. The range of colors goes from red to green, then to blue, then back to red.
