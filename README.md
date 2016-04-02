## RotaryClickEncoder for Arduino DUE 


### About

This is an example scetch for Rotary Click Encoders (sometimes called „quadratur encoder“ with button) for the Arduino DUE.
Took me some time finding the right scetch that I could adapt. Credits go to [HaWe] (http://www.mindstormsforum.de/viewtopic.php?t=8624).


### Use

Get the values of the rotary encoders and buttons by calling:
```
encVal[ #];    // get encoder value (# = Encoder number)
enc#ButStat;   // get button state
enc#ButCount;  // get count of button pushes
enc#ButTog;    // get toggle state of button switch
```

If you want to add more encoders make sure to edit "ClickEncoderSetup.h" accordingly.
Sorry if the code might look kind of clunky, still a noob.

Please make sure the to include [Ivan Seidels „DueTimer“](https://github.com/ivanseidel/DueTimer) to your library folder!


