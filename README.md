# iCar
Created an "Intelligent Car" using Aruduino, which follows black lines on a track with a contrasting 
surface (usually white).

# Setup:
1. Load iCar.ino in the Arudino IDE
2. Connect the Arduino Board to your device
3. Make sure Arduino Board is connected under "Tools > Board"
4. Place the iCar on a white board with dark lines, with a black line on the left of it.
5. Upload the program onto the board

# Materials Used to make iCar:

## Car
- Copper Wires
- Arudino Board
- AA Batteries (4)
- 9V Battery
- Battery Pack (AA Batteries)
- Gearbox with 2 motors
- LDR Sensors (2)
- Breadboard
- Wood Platform

## Car Cover
- Styrofoam Board
- Construction Paper
- Glue

## How it works:
The iCar works by making sure one LDR sensor is always on a black line and the other is always on the 
brighter surface, allowing the car to move alongside the line. 

1. If the car senses both sensors on the black line, it moves rightwards. 
2. If the car senses both sensors on the contrasting (white) surface, it turns
leftwards while backing up to find and align itself with the next black line it senses. 

Otherwise, the car moves forwards and leftwards (leftwards into the black line, reaching case 1).
