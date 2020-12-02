# Physics 4AL Group Project
7-segment display reaction time tester

### Components:
* 7-segment display
* 5 buttons
* Arduino Uno
* 2 x 330 ohm resistor

### Default Pinout:  
    SEG_A       7  
    SEG_B       8  
    SEG_C      A3  
    SEG_D      A2  
    SEG_E      A1  
    SEG_F       6  
    SEG_G       5  
    SEG_PERIOD  3  
    
    BUTTON_1    9  
    BUTTON_2   10  
    BUTTON_3   11  
    BUTTON_4   12  
    BUTTON_5   13  
    
    330 ohm resistors on each Common Cathode (CC) pin of the 7-segment display

Note: more proper way to do this would be to connect CC directly to ground, and use an individual current limiting resistor per segment pin, but lacked resistors, patience and space on my breadboard
