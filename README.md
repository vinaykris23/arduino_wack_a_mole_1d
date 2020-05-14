# arduino_wack_a_mole_1d


## Problem Statement:
	To design and implement a game using Arduino.
	Game: Wack-A-Mole 1D

## Description:
Connect a disc (cardboard or similar) to a servo motor. Stick or draw a symbol onto one part of the disc. Another cardboard or a box around this installation only allows to see one small segment.
The servo motor is randomly moving the disc around. Whenever the player is able to see the symbol, he/she has to press a button. Think of a level and points system for this game.

## Design:
Two servo motors in parallel are synchronised to increase the speed of the rotating cardboard.
Game starts when the cardboard begins to rotate.
When the user sees the symbols in the cardboard through the whole, the user inputs by pressing the button. Since we are using a Servo Motor, we use the position feedback from the motor for checking if the input is correct or wrong .
If the Input is CORRECT, the user SCORES A POINT and LED turns ON.
If the Input is WRONG, Buzzer goes off.
Three wrong inputs and GAME is OVER.
For every successive 5 points scored, the rotational speed of the cardboard increases, thus increasing the difficulty level of the game.
