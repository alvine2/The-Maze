# alx portfolio project (The-maze)

![Description of the image](https://github.com/alvine2/alx_maze-project/blob/main/pics/readme_gif.gif?raw=true)


## Table of Content
- [Introduction](#introduction)
- [Prerequisites](#prerequisites)
- [Installation](#concept)
- [Game control](game-controls)
- [Tools Used](#tools-used)
- [Contributor](#contributor)


## Introduction
Electrifier Maze is a simple game built using the Raycasting technique. It was built to serve as my portfolio project. I chose this project to because of my curiosity to explore game development. The goal of the game is to find your way from one end of the map (where the player was initially spawned with black walls) to the other end of the map (with white walls).

## Prerequisites
- Debian/Ubuntu or Fedora OS
- A Bash terminal
- A user with superuser privilege
- git - Click this link and follow the instructions to [install git](https://github.com/git-guides/install-git#install-git-on-linux) on your machine.

This game was built to be compiled and ran on a linux machine only.


## Installation
Using a Bash terminal, run the commands after the `$` sign below.
- Clone the repository

	```bash
	user@user-pc:~/$ git clone https://github.com/alvine2/alx_maze-project.git
	Cloning into 'alx-maze_project'...
	...
	```

- Install SDL2 library on your respective machine

	```bash
	user@user-pc:~/$ ./install_sdl2.sh
	Reading package lists... Done
	Building dependency tree... Done
	Reading state information... Done
	...
	```

- Compile the game files

	$ gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`;


## Game controls
Used this keys to navigate your way around the game.
| Keys			| Function	|
|  :-------		| :---------	|
| `w` or `up arrow`	| Move forward  |
| `s` or `down arrow`	| Move backward |
| `a` or `left arrown`	| Turn left	|
| `d` or `right arrow`	| Turn right	|


## Tools Used
As part of the project requirement, the game was built using the SDL2 library and Raycasting Technique.
- ChatGPT: ChatGPT is a language model developed by OpenAI. It generates human-like text responses to text inputs.
	ChatGPT was used for researching to better understand the Raycasting technique and SDL2 library.
	It also suggested better ways to implement some designs, like the game map and so on.

- Raycasting: Raycasting is a rendering technique that creates 3D perspective from a 2D map. The 2D map used in this game is stored in a [file](/map/map1.txt), which is then extracted by a function that reads the file line by line and stores each character in a 2D array representing the length and breadth of the map. For more information about Raycasting, click [here](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/).

- SDL2: SDL (The Simple DirectMedia Layer) is a cross-platform development library, designed to allow low level access to audio, video, mouse, keyboard and graphics hardware via OpenGL and Direct3D. SDL2 is the second version of the SDL library. For more information about SDL2, click [here](https://lazyfoo.net/tutorials/SDL/index.php).

## Contributors
- [Kinyera alvine](https://github.com/alvine2/alx_maze-project.git)
