Find the shortest path within a graph by experimenting with different shortest path algorithms.

Algorithms include:
- Floyd-Warshall
- Bellman-Ford
- Coming Soon: Depth First Search, Breadth First Search, A * Search, Greedy First Search, & more!

Video installation/deployment demo: https://youtu.be/4PDCZJnXUEk

## Instructions

0. Before you run the program, drop the dataset files you would like to use into the __InputFiles__ directory. There is 2 datasets already included, which you may delete.

__Method 1 (FASTEST)__ - Linux Only:

1. Download latest [linux release](https://github.com/luisegarduno/Various-ShortestPath-Algorithms/releases/download/v1.0/LinuxRelease.zip)
2. Run: ` $ ./ShortestPath`

__Method 2 (QUICK)__ - local build:

1. Build project + Create executable:
```bash
mkdir build; cd build; cmake ..; make -j 2 optimize=no debug=yes > /dev/null; mv ShortestPath ../
```
2. Done! To deploy: `./ShortestPath`

__Method 3 (noob)__ - local build:

This method is the same as method 1, but in baby steps.

1. Create build environment: `$ mkdir build; cd build` 
2. Build the project: `cmake ..`
3. Create executable: `make -j 2 optimize=no debug=yes > /dev/null`
4. Move file to project directory: `$ mv ShortestPath ../`
5. Done! To deploy: `./ShortestPath` 
