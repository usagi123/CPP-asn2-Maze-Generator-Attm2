Maze generator
=

Solution by Huy Mai Pham Quang (s3618861@rmit.edu.vn)

### Description
There are 3 algorithm to generate maze
- Growing tree
- Prim's
- Recursive backtracking

The program can be able to generate maze from user input seed, width and height. 
Then it will be an option to saved both SVG and binary.

### Installation
Go to the source code directory and call
    `cmake .`

Then `make`


### Usage

--gg: Growing tree algorithm with custom seed

-gg: Growing tree algorithm with ramdom seed

--gr: Recursive backtracking algorithm with custom seed 

-gr: Recursive backtracking algorithm with random seed

--gp: Prim's algorithm with custom seed

-gp: Prim's algorithm with random seed

--sv: Export maze to SVG

--sb: Export maze to binary

Param: ./mazer -algorithm flag -export file type

Example: ./mazer --gg 123 1000 1000 --sv mygrowingtreemaze.svg



