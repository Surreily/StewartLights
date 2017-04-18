# Stewart's Lighting

This is a simple lighting project I am working on for my uncle. It uses an Arduino board (or a suitable ATMEGA/ATTINY) to control a string of RGB NeoPixels. The finished product is designed to be connected to a button that cycles through various patterns. 

As of writing this document, the project is far from finished - there is an unfinished `RainbowPattern` class in here somewhere and the button functionality has yet to be implemented.

## General Use

The string length and pins can be defined in the main file.

    #define STRIP_LENGTH 30

    #define STRIP_PIN 13
    #define BUTTON_PIN 9

You can change the default pattern by changing the default index (inside the `setup` method):

    void setup() {
        ...
        index = 4; // Start on the fifth pattern.
        ...
    }

## Adding Patterns

You can create your own patterns by extending the `Pattern` class. If you extend the constructor, be sure to pass `len` to the base constructor too. Your class should also override the `show` method to implement custom logic.

You will also need to add the pattern to the `PatternFactory` class's `createPattern(index)` method, and ensure that `NUM_PATTERNS` is set equal to the number of patterns defined inside that method.

### Helper Functions

The base `Pattern` class includes some helper functions to make patterns easier to produce:

* *wheel(strip, pos)*: Returns a colour from a given input (from 0 to 255). Passing in 0 returns red, and higher values will return higher values in the colour wheel. This function requires the `Adadruit_NeoPixel` strip object to be passed in.
* *wheelRed(pos)*, *wheelGreen(pos)*, *wheelBlue(pos)*: Returns the corresponding colour given the position. For example, calling `wheelRed(0)` will return 255, while the other two functions will return 0.

### Example: Static Color Pattern

In this example, we will cover the static pattern included. This pattern displays a single colour and doesn't change. The constructor takes in the required `len` parameter along with a `color` ranging from 0 to 255 that will later be passed into the `wheel` helper function.

    StaticPattern::StaticPattern(int len, int color) {
        _len = len; // Set the length of LED strip (required).
        _color = color; // Set private colour property.
    }

We implement a destructor to free any resources that are removed upon deletion. In this example, we don't need to include any code inside.

    StaticPattern::~StaticPattern() {
        // Nothing.
    }

Finally, we implement the `draw` method. This takes an `Adafruit_NeoPixel` parameter that allows us to communicate with the LED strip. We set each LED equal to the `_color` private field and call the `show` function on the strip when done.

    void StaticPattern::draw(Adafruit_NeoPixel* strip) {
        // Set the pixels.
        for (int i=0; i<_len; i++) {
            // We use the wheel helper function to get a color.
            strip->setPixelColor(i, wheel(strip, _color));
        }
        strip->show();
    }

Finally, we increase `NUM_PATTERNS` in the main file by one and add a new entry to the switch statement inside the `PatternFactory`.

    PatternFactory::createPattern(int index, int len) {
        switch(index) {
            ...
            case 9: return new StaticPattern(len, 0); // Red
            case 10: return new StaticPattern(len, 80); // Green
            case 11: return new StaticPattern(len, 160); // Blue
            ...
        }
    }

For a full implementation, check the `StaticPattern.h` and `StaticPattern.cpp` source files.
