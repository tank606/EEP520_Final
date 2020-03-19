EE P 520: Final Project
==
## Project Goal
The project goal is to save the princess prevent her from attacking by the Lord of the Dark Castle. A user-controlled agent (knight) needs to pass through the blockade of other automatic agents (ghost, guard), and also needs to find the corresponding key in order to unlock the corresponding door. Without wasting time, the knight has the responsibility to save the princess through the castle. User-controlled robots can only move and jump left and right, while ghost is a specific area that can hover back and forth and guard the entire castle can move.

## Game Description and Instructions
In this video game, you, as a knight, are trying to go to the castle to save the princess! You (round object) are running knights. It is your job to enter the depths of the castle before the Lord of the Dark Castle (the red square robot). The latter finds out that you have entered and plans to kill the princess within a certain time. If you exceed the time, you will lose the princess forever. But beware, there are ghosts and guards everywhere in the castle, but warping guards (blue square robots). They can tolerate seeing you running around, but they will not tolerate you touching them. Touch them, and you're back at the beginning of the castle gate! Don't let yourself be caught by the trap (brown triangle on the map)! Touch the trap will also take you back to where you started. When you find the princess, you and the princess will return to the entrance position together.

## Installing & playing the game
Please note that the following steps are based on a Windows 10 computer. Mac computers follow similar steps, but some steps may be slightly different. However, the overall process for both systems remains the same.

Here are the steps to install and play the game:

1. Make sure you have git installed on your computer and clone repository into a folder on your local drive
git clone https://github.com/arodzUW/EEP520-FinalProject.git
cd EEP520-FinalProject

2. The project uses ELMA and ENVIRO software packages. Repositories and information on how to use them, call them, and implement them can be found in the links shown below:

ELMA
ENVIRO 

3.  Make sure that Docker is installed on your computer. Both ELMA and ENVIRO are pre-loaded into Docker images / containers, which makes calling these packages easier. Go to the directory where you copied the project and do the following in a terminal window:

docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4?? bash

4. To run the game: in the terminal, within the EEP520-FinalProject directory run
cd SavePrincess
esm start

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








In this video game, you, as a knight, are trying to go to the castle to save the princess! You (round object) are running knights. It is your job to enter the depths of the castle before the Lord of the Dark Castle (the red square robot). The latter finds out that you have entered and plans to kill the princess within certain time. You will lose the princess forever. But beware, there are ghosts everywhere in the castle, but warping guards (blue square robots). They can tolerate seeing you running around, but they will not tolerate you touching them. Touch them and you're back at the beginning of the castle gate! What do you think you have? Defeat the commander, defeat the defender ... oh! ... and don't let yourself be caught by the camera (brown triangle in the map)! Touch the camera and the vigilant unbent guard will take you back to where you started. After completing the castle operation, you and the princess will return to the entrance position together. Can you do it, or stay at the castle gate forever?





This project implements a user-controlled agent (knight) that can navigate through the maze, while other automatic agents (ghosts) can move through the maze, allowing you to count down and monitor the maze lobby. Without wasting time, the knight has the responsibility to save the princess through the maze. For a more in-depth description of simulation features and video game descriptions, see the Usage section. User-controlled robots can only move and jump left and right, while automated robots patrol back and forth, while other robots do not move at all.

## Game Description and Instructions


In this video game, you, as a knight, are trying to go to the castle to save the princess! You (round object) are running knights. It is your job to enter the depths of the castle before the Comisioner (the red square robot). The latter finds out that you have entered and killed the princess with torture. You will lose the princess forever. But beware, there are ghosts everywhere in the castle, but warping guards (blue square robots). They can tolerate seeing you running around, but they will not tolerate you touching them. Touch them and you're back at the beginning of the castle gate! What do you think you have? Defeat the commander, defeat the defender ... oh! ... and don't let yourself be caught by the camera (brown triangle in the map)! Touch the camera and the vigilant unbent guard will take you back to where you started. After completing the castle operation, you and the princess will return to the entrance position together. Can you do it, or stay at the castle gate forever?


## Installing & playing the game
Here are the steps to install and play the game:

1. Clone repository into a folder on your local drive
2. Open up a terminal window and move into `/breakout_enviro/` folder
3. Run the docker image : `docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.6 bash`
4. Type and run the command in your terminal window : `esm start`
5. Open up a browser and go to your [localhost address](http://localhost/)
6. Go back to your terminal window and run command `make`
7. Now run command `enviro`
8. The game should now start in your browser. Use the left and right arrows to move the paddle.
9. Have fun?


## Agents Introduction

### knight
The player agent is you, a knight, a user-controlled robot. The player_agent.h file controls the functions of the robot. In simple terms, once the simulation begins, the robot has a main category that defines its behavior: "playerAgentController." The PlayerAgentController class defines the actions that the robot should perform when a key on the keyboard is pressed, and which direction the robot should move when a key is pressed. This class also "monitors" events sent by other classes and responds to them when appropriate. For more details, see the remaining in-code comments in the .h file. Under the playerAgentController class.

Note that the objects in the map (robots and walls) are defined in the config.json, player_agent.json, camera_robot.json, time_robot.json, and monitor_robot.json files.

### Princess



### The Commisioner
Commissioner is a red robot that moves towards the end of the lobby during the simulation. The commissioner is code-named "time_robot," and the time_robot controls all its functions.h file. Two main classes control the functionality of Commissioner, moveF, and Stopped. The "moveF" class controls the speed at which the robot moves forward, and the "Stoppped" class controls the operation when it reaches the end of the lobby. For more details, see the remaining in-code comments in the .h file. The following is a representation of the two classes.

### The Guards
Guards are scattered blue robots that navigate the map. The code for the guard is "monitor_robot," and the monitor_robot controls all its functions.h class. There are two main classes of control guard jobs: forward and angle. The forward motion controls the forward movement of the robot, while the angle controls the rotational motion of the robot. For more details, see the remaining in-code comments in the .h file. The following is a representation of the two classes.

### The Cameras
Given that these cameras are static "robots" and do not need to move on a map, they are programmed differently than all other robots. Using the default class automatically generated when ENVIRO's ESM create function is called, you can detect when other objects interact with it. All camera functions are built into the class. For more details, see the remaining in-code comments in the .h file. The following is a representation of this class.


## Key Development Challenges
There are not too many challenges in my project, that took me some time to figure out. Since my previous major is bioengineering, this course is my first exposure to C++. These challenges, that maybe easy for an experienced academic, made me struggle and learn a lot.



- Monitor robots wandering: Before having the final code as it is, I attemped to have more sensors and logic behind the control of the monitoring robots. The re-occuring problem I had was the the robots would continually get stuck around the edges or once hit a dead end, they would not turn 180 degrees to return, but simply stop moving. The problem was addressed by randomizing the left / right turns. Original logic implemented by turning the robot based on the available space left or right, did not worked.

- Collision detection: It took me some time to figure out how to emit and watch for an event between different classes. I knew that part of the functionality I wanted the game to have was that if the user touches the cameras in the game or the guards, it would instantaneously return to the initial position. Being able to send that message between different classes, was not easy to solve (for me).
- Developing the maze: Although hw8 was cancelled, for it I had developed a maze with a bot that would autonomously navigate through it. Figuring out the coordinates and shape of the maze along with the program behind having a bot autonomously navigate through it was definitely a challenge.

- Design of the castle. How to design a maze reasonably needs to weigh the fun and difficulty. Too rich elements will make the game more difficult. At the beginning of the project, I added as many elements as possible to the castle to make the game fun. However, when I tested the game, I found that the game became more difficult, and different elements directly tried to conflict. In addition, using code to build visualization components is a time-consuming and laborious task. Each time you need to predict the coordinates, then modify the code, compile, and finally check whether it is correct from the web page. This process is continuously cycled until the end. Here, I hope that the teacher can adjust the element coordinate display function in an interface, and the mouse can display its coordinates from the corner to the corner.











This repository contains the complete implementation of the final project developed for the EEP520 course, embedded application software engineering provided by the University of Washington. 
This project implements a user-controlled agent (knight) that can navigate through the maze, while other automatic agents (ghosts) can move through the maze, allowing you to count down and monitor the maze lobby. Without wasting time, the knight has the responsibility to save the princess through the maze.
For a more in-depth description of simulation features and video game descriptions, see the Usage section.
User-controlled robots can only move and jump left and right, while automated robots patrol back and forth, while other robots do not move at all.

The ELMA and ENVIRO software packages are used to implement this project. For more information about this software package, see the installation section of this README.md file.


## Installation - Windows 10
Please note that the following steps are based on a Windows computer. Mac computers follow similar steps, but some steps may be slightly different. However, the overall process for both systems remains the same.

First, make sure you have git installed on your computer (write git in a terminal window and run it). If it is not installed, go to https://git-scm.com/download/win. Then create a directory on your computer for this repository and make it your working directory. Clone this repository into your computer directory by running the following command:
```bash
git clone https://github.com/arodzUW/EEP520-FinalProject.git
cd EEP520-FinalProject
```
Now, you should have everything in this repository on your computer.

As mentioned above, the project uses `ELMA` and `ENVIRO` software packages. Repositories and information on how to use them, call them, and implement them can be found in the links shown below:

- [ELMA](https://github.com/klavinslab/elma)<br />
- [ENVIRO](https://github.com/klavinslab/enviro) <br />

The next set of instructions is about how to use the built-in ENVIRO / ELMA to set up the development environment without having to clone the two software packages that make ENVIRO and ELMA. To do this, make sure that Docker is installed on your computer. Both ELMA and ENVIRO are pre-loaded into Docker images / containers, which makes calling these packages easier. After installing Docker on your computer, go to the directory where you copied the project and do the following in a terminal window:
```bash
docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.4 bash
```

* Please note that when creating these projects, version 1.4 of ENVIRO was used, and other versions may have been uploaded since then. For more information on the latest versions and updates, refer to ENVIRO's repository. If you encounter compilation issues, make sure to use a compatible ENVIRO version.

After completing these steps, your terminal should run under "root @ ...", which means you are working inside a container. You are now ready to run the project.

## Usage
In this video game, you, as a knight, are trying to go to the castle to save the princess! You (round object) are running knights. It is your job to enter the depths of the castle before the Comisioner (the red square robot). The latter finds out that you have entered and killed the princess with torture. You will lose the princess forever. But beware, there are ghosts everywhere in the castle, but warping guards (blue square robots). They can tolerate seeing you running around, but they will not tolerate you touching them. Touch them and you're back at the beginning of the castle gate! What do you think you have? Defeat the commander, defeat the defender ... oh! ... and don't let yourself be caught by the camera (brown triangle in the map)! Touch the camera and the vigilant unbent guard will take you back to where you started. After completing the castle operation, you and the princess will return to the entrance position together. Can you do it, or stay at the castle gate forever?

To run the game / simulation: in the terminal, within the `final` directory run: <br />
```bash
cd final
esm start
```
For an in-depth explanation of what does `esm start` does, refer to ENVIRO's documentation. Simply put, it begins "broadcasting" to `localhost` webpage the simulation. To test, go to your web-browser and enter `localhost`. Now you should see a message in the screen stating: "Enviro Error: No connection. Is the server running?...". This error appears because the simulation has not yet been ran. To run the simulation, from inside the `MazEscape` directory run: <br />
```bash
enviro
```
At this point you should see in the `localhost` webpage the simulation running and the automated robots moving around. Once in the simulation, you are attempting to save the princess and the Commisioner has already started making his way to the lockdown button.

To manually control the prisoner (circled robot) use keys ` ` for jumping, `A` for left, and `D` for right. The simulation can be stopped at any time by using `ctrl + c` in the terminal. If need to re-run the simulation, simply run `enviro` in the terminal. 

The red automated robot is the counter. Once the robot reaches the end of the hall, if you have not yet reached your destination, you lose and a message stating that you didn't make it will appear on top of your robot. If you make it to the end, and wait until the Commisioner reaches the end, a message stating that you escaped will appear over your robot. Happy games! 


## Project Functionality


### knight
The player agent is you, a knight, a user-controlled robot. The player_agent.h file controls the functions of the robot. In simple terms, once the simulation begins, the robot has a main category that defines its behavior: "playerAgentController." The PlayerAgentController class defines the actions that the robot should perform when a key on the keyboard is pressed, and which direction the robot should move when a key is pressed. This class also "monitors" events sent by other classes and responds to them when appropriate. For more details, see the remaining in-code comments in the .h file. Under the playerAgentController class.

Note that the objects in the map (robots and walls) are defined in the config.json, player_agent.json, camera_robot.json, time_robot.json, and monitor_robot.json files.

### Princess


### The Commisioner
Commissioner is a red robot that moves towards the end of the lobby during the simulation. The commissioner is code-named "time_robot," and the time_robot controls all its functions.h file. Two main classes control the functionality of Commissioner, moveF, and Stopped. The "moveF" class controls the speed at which the robot moves forward, and the "Stoppped" class controls the operation when it reaches the end of the lobby. For more details, see the remaining in-code comments in the .h file. The following is a representation of the two classes.

### The Guards
Guards are scattered blue robots that navigate the map. The code for the guard is "monitor_robot," and the monitor_robot controls all its functions.h class. There are two main classes of control guard jobs: forward and angle. The forward motion controls the forward movement of the robot, while the angle controls the rotational motion of the robot. For more details, see the remaining in-code comments in the .h file. The following is a representation of the two classes.

### The Cameras
Given that these cameras are static "robots" and do not need to move on a map, they are programmed differently than all other robots. Using the default class automatically generated when ENVIRO's ESM create function is called, you can detect when other objects interact with it. All camera functions are built into the class. For more details, see the remaining in-code comments in the .h file. The following is a representation of this class.

## Project Supplementary Information

## Key Development Challenges
During the development of this project, I encountered some challenges that took me some time to figure out. Fully public and an educated biology engineer, this course is my first course in programming and C / C ++. For me, the challenge may not be a challenge at all for an experienced programmer. See the list below for the main challenges:

- Design of the castle. How to design a maze reasonably needs to weigh the fun and difficulty. Too rich elements will make the game more difficult. At the beginning of the project, I added as many elements as possible to the castle to make the game fun. However, when I tested the game, I found that the game became more difficult, and different elements directly tried to conflict. In addition, using code to build visualization components is a time-consuming and laborious task. Each time you need to predict the coordinates, then modify the code, compile, and finally check whether it is correct from the web page. This process is continuously cycled until the end. Here, I hope that the teacher can adjust the element coordinate display function in an interface, and the mouse can display its coordinates from the corner to the corner.


## Sources Used

The project was fully developed using as a baseline the pre-loaded ENVIRO examples along with the documentation for functionalities implementation. Other minor sources from Google searches were referenced to search for more basing functionalities and C++ documentation.

