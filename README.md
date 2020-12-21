# Signalex

Control one of these bad boys over i2c!

![img](https://www.scoretronics.com/components/402L.jpg)

Reliant on the Adafruit `Adafruit_MCP23017.h` library. 

## Directions

Once you've imported it, you can create an instance with

```
Signalex mySignalex = Signalex(0); //Or 1, or 2... etc up to 7

//Or you can change the address with
mySignalex.setAddress(3);

//Once you are ready, in Setup, call

mySignalex.setup();
```

Using it can be a bit odd, since these Signalex displays do not work like LEDs. Each segment has a magnet that flips it on or off. Additionally, these magnets need to be charged to engage a flip, and then discharged.

So to flip a segment on, the code would be

```
//The 'true' denotes that we are targetting the coil that flips it 'on'
mySignalex.setSegmentOn(0, true); //Activate ON coil
delay(75); //Give it time to flip
mySignalex.setSegmentOff(0, true); //Deactivate ON coil
```

And then to turn that segment off:

```
mySignalex.setSegmentOn(0, false); //Activate OFF coil
delay(75); //Give it time to flip
mySignalex.setSegmentOff(0, false); //Deactivate OFF coil
```

## Numbering

As I post this, I'm facepalming because I realized I left my notebook in another state. I believe these are organized by starting at the bottom right and moving clockwise.