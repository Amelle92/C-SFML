#Adam Melle
#91.204.202 Project Portfolio
#May 4th, 2015


#Contents:

PS0 Hello World

PS1 Recursive Graphics

PS2a Linear Feedback Shift Register  
PS2b Image Encoding

PS3a N-Body Simulation (Static)
PS3b N-Body Simulation (Animated)

PS4 DNA Sequence Alignment

PS5a Ring Buffer
PS5b Karplus-Strong String Simulation and Guitar Hero

PS6 Markov Model of Natural Language

PS7a Kronos Time Clock Log Parsing Boot Parsing



#PS0 Hello World

	The purpose of this assignment was to set up our Linux environment and experiment with the SFML demo code. Once we got the SFML demo code to run successfully, we were asked to draw our own sprite and make it respond by moving via keystrokes. We were also asked to add one additional feature, and I chose to have my sprite change colors when it collided with the edge of the window. One of the key algorithms of the test code was the nested while loop for window.isOpen and window.pollEvent(event). This was immediately familiar to me because it is very closely related, if not identical, to “the game loop”, used in game development. The algorithm is essentially an infinite loop used for updating sprite positions, variables, or anything you want to change in your program every frame. By having the sprite coordinates increment by 2 in a direction depending on the key pressed every time the loop executes, I can make the sprite move across the window. I hadn't had experience with SFML at all before this assignment, so I learned how to create sprites, textures, and shapes as well as how to display them in an SFML window.

                       Sprite moving around                                     Sprite changing color on collision
