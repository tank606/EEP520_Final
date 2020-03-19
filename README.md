EE P 520 Final Project
==
## Project Goal
The purpose of this project was to use C++ and multi-agent systems to build a Room Escape game. You need to control a knight to save the princess prevent her from attacking by the Lord of the Dark Castle. A user-controlled agent (knight) needs to pass through the blockade of other automatic agents (Ghost, Guard and Trap), and also needs to find the corresponding key in order to unlock the corresponding door. User-controlled robots can only move and jump left and right, while Ghosts work on a specific area and Guards can patrol the entire castle.

## Game Description and Instructions
In this game, you, as a knight, are trying to pass the castle to save the princess! The Lord of the Dark Castle (the red square robot) finds that you had entered the castle and he was very angry and wanted to kill the princess. You should take the princess before he approaches the princess. If you exceed the time, you will lose the princess forever. But there are ghosts and guards everywhere in the castle. You can appear in the guard's field of vision, but you cannot touch him. Ghosts will only appear in certain places, you need to find the right time to avoid them.Don't let yourself be caught by the trap (brown triangle on the map)! Touch guard, ghost and traps, and you're back at the beginning of the castle gate! When you find nowhere else to go, try to find a hidden key. Get it and the hidden door will open. When you find the princess, you and the princess will return to the entrance position together.

## Installing & playing the game
Please note that the following steps are based on a Windows 10 computer. Mac computers follow similar steps, but some steps may be slightly different. However, the overall process for both systems remains the same.

Here are the steps to install and play the game:

1. Make sure you have git installed on your computer and clone repository into a folder on your local drive

```bash
git clone https://github.com/arodzUW/EEP520_Final.git
cd EEP520_Final
```

2. The project uses `ELMA` and `ENVIRO` software packages. Repositories and information on how to use them, call them, and implement them can be found in the links shown below:

- [ELMA](https://github.com/klavinslab/elma)<br />
- [ENVIRO](https://github.com/klavinslab/enviro) <br />


3.  Make sure that Docker is installed on your computer. Both ELMA and ENVIRO are pre-loaded into Docker images / containers, which makes calling these packages easier. Go to the directory where you copied the project and do the following in a terminal window:

```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4 bash
```

4. To run the game: in the terminal, within the EEP520-FinalProject directory run
```bash
esm start
```

5. Open up a browser and go to your [localhost address](http://localhost/)

6. Compile and run the game, from inside the SavePrincess directory run:
make
enviro

7. The game should now start in your browser. Use the space, "a" and "d" key to move the knight.

8. Enjoy the game.


## Agents Introduction

### Knight
The player agent is you, a knight, a user-controlled robot. The knight.h file controls the functions of the robot. In simple terms, once the simulation begins, the robot has a main category that defines its behavior: "KnightController." The KnightController class defines the actions that the robot should perform when a key on the keyboard is pressed, and which direction the robot should move when a key is pressed. This class also check events sent by other classes and responds to them when appropriate. For more details, see the remaining in-code comments in the .h file. Under the KnightController class.

### Princess
The princess is a pink robot and is waiting for you to save. Princess is codenamed "princess," and all its functions are controlled by the princess.h file. The princess doesn't need to do anything, just wait for the knight. Corresponding to this class, you only need to detect the arrival of the knight in init(). For more details, see the remaining in-code comments in the .h file.

### Keys and Gates
For fun, I added the ability to find keys and open doors. You have to find the corresponding keys in order and open the corresponding doors. Repeat the cycle until the last door is finally opened. I added collision detection in key.h for knight and throws the event key and deletes the current key. This event is detected in gate.h, and then the corresponding gate is removed.

### The Lord of the Dark Castle
The Lord is the red robot watching the princess. It is code-named "Lord" and the master controls all its functions.h files. Two main classes control the main functions, moveF and Stopped. The "moveF" class controls the speed at which the robot moves forward, and the "Stoppped" class controls the operation when the robot reaches the princess. For more details, see the remaining in-code comments in the .h file.

### The Guards
The guards are scattered blue robots that can navigate on the map. The code of the guard program is "guard," and the guard controls all its function.h classes. The work of the controller is divided into two categories: forward and tilt. The forward motion controls the forward motion of the robot, while the angle controls the rotational movement of the robot. For more details, see the remaining in-code comments in the .h file.

### The Traps
Given that these traps are static "robots" and do not need to move on a map, they are programmed differently than all other robots. Using the default class automatically generated when ENVIRO's ESM create function is called, you can detect when other objects interact with it. All trap functions are built into the class. For more details, see the trap in-code comments in the .h file. 



## Key Development Challenges
During the development of this project, I encountered some challenges that took me some time to figure out. Fully public and an educated biology engineer, this course is my first course in programming and C / C ++. For me, the challenge may not be a challenge at all for an experienced programmer. See the list below for the main challenges:

- Design of the castle. How to design a maze reasonably needs to weigh the fun and difficulty. Too rich elements will make the game more difficult. At the beginning of the project, I added as many elements as possible to the castle to make the game fun. However, when I tested the game, I found that the game became more difficult, and different elements directly tried to conflict. In addition, using code to build visualization components is a time-consuming and laborious task. Each time you need to predict the coordinates, then modify the code, compile, and finally check whether it is correct from the web page. This process is continuously cycled until the end. Here, I hope that the teacher can adjust the element coordinate display function in an interface, and the mouse can display its coordinates from the corner to the corner.


## Sources Used

The project was fully developed using as a baseline the pre-loaded ENVIRO examples along with the documentation for functionalities implementation. Other minor sources from Google searches were referenced to search for more basing functionalities and C++ documentation.

