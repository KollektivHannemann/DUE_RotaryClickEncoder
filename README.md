## RotaryClickEncoder for Arduino DUE 


### About

This is an example scetch for Rotary Click Encoders (sometimes called „quadratur encoder“ with button) for the Arduino DUE.
Note that this is not a real library. Just start the *.ino file from the downloaded folder.
 
Took me some time finding the right scetch that I could adapt, so I thought I would share it.  Credits go to [HaWe] (http://www.mindstormsforum.de/viewtopic.php?t=8624).


### Use

Please make sure the to include [Ivan Seidels „DueTimer“](https://github.com/ivanseidel/DueTimer) to your library folder!

Get the values of the rotary encoders and buttons by calling:
```
encVal[ #];    // get encoder value (# = Encoder number)
enc#ButStat;   // get button state (# = Encoder number)
enc#ButCount;  // get count of button pushes (# = Encoder number)
enc#ButTog;    // get toggle state of button switch (# = Encoder number)
```

If you want to add more encoders make sure to edit "ClickEncoderSetup.h" accordingly.

Sorry if the code does look kind of clunky, still a noob.




