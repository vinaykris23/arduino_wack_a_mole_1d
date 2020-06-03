# arduino_wack_a_mole_1d


## Problem Statement:
	To design and implement a game using Arduino.
	Game: Wack-A-Mole 1D

## Description:

Create a Wack-A-Mole Game on arduino uno with the help of 4 LEDs and 4 buttons. 
The player starts the game by pressing a button and the LEDs start blinking and based on the each LED a button is paired and hitting the button inside a specific time frame rewards the player with some points and if he missed the buttons or presses the  wrong one he will get a strike. A total of 5 can be accumulated before the game finishes.


## Design:

Two servo motors in parallel are synchronised to increase the speed of the rotating cardboard.
Game starts when the cardboard begins to rotate.
When the user sees the symbols in the cardboard through the whole, the user inputs by pressing the button. Since we are using a Servo Motor, we use the position feedback from the motor for checking if the input is correct or wrong .
If the Input is CORRECT, the user SCORES A POINT and LED turns ON.
If the Input is WRONG, Buzzer goes off.
Three wrong inputs and GAME is OVER.
For every successive 5 points scored, the rotational speed of the cardboard increases, thus increasing the difficulty level of the game.
