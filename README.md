# arduino_wack_a_mole_1d


## Problem Statement:
	To design and implement a game using Arduino Uno.
	Game: Wack-A-Mole 1D

## Description:

Create a Wack-A-Mole Game on arduino uno with the help of 4 LEDs and 4 buttons. 
The player starts the game by pressing a button. 
The LEDs start blinking in random order.
When the LED is on and if the respective button is pressed within a specified time frame, the player scores points.
If the player fails to press the button within a specific time frame, the player gets a strike.
A total of 5 strikes means the game is finished.


## Design:



## Pin Setup

| Arduino Pin | Description |
| --- | --- |
|  2 | Yellow Button |
|  3 | Yellow LED |
|  4 | Red Button |
|  5 | Red LED |
| 10 | Pink Button |
| 11 | Pink LED |
| 12 | Green Button |
| 13 | Green LED |
| A5 | Buzzer |


## Variables Used 
| Variables Used | Description |
| --- | --- |
|  score | Keeps track of the players score for the current game played. Initial value is 0 |
|  strike | Count of strikes the player has received in the current game played. If strike=5 , the game is finished |
|  points | The increment given to score on each successful hit. This value increases with the difficulty level of the game. Initial value is 100 |
|  lifeSpan | Duration for which the LED blinks. This value reduces with the difficulty level of the game |


## Working Setup

1.Download the code and upload the game to the arduino.
2.Open the Serial Monitor for viewing the score of the game.
3.Enjoy playing the game!!!
