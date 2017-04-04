# Stewart's Lighting

This is a simple lighting project I am working on for my uncle. It uses an Arduino board (or a suitable ATMEGA/ATTINY) to control a string of RGB NeoPixels. The finished product is designed to be connected to a button that cycles through various patterns. 

As of writing this document, the project is far from finished - there is an unfinished `RainbowPattern` class in here somewhere and the button functionality has yet to be implemented.

## General Use

The string length and pins can be defined in the main file. The button code is not yet implemented.

    #define STRIP_PIN 13
    #define BUTTON_PIN 9

You can change the default pattern in the Arduino `setup()` function by setting `patt` to any instance of `Pattern` you wish.

    patt = new FirePattern(STRIP_LENGTH, 30, 45);

## Adding Patterns

You can create your own patterns by extending the `Pattern` class. If you extend the constructor, be sure to pass `len` to the base constructor too. Your class should also override the `show` method to implement custom logic.
