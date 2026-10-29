# File System Representation and Search Using BFS and DFS

**Activity:** Challenge 17 – B 09  
**Course:** Data Structures and Algorithms  
**Language:** C

## Aim
Represent a simplified file system as a graph using an adjacency matrix. Search for a specified file with Breadth-First Search (BFS) and Depth-First Search (DFS), showing each traversal order and whether the target was found.

## How it works
- Each file or directory is represented by a node.
- Each connection between nodes is represented by an edge.
- The adjacency matrix stores the graph connections.
- BFS explores connected nodes level by level using a queue.
- DFS explores one path as far as possible before backtracking, using recursion.
- The example treats connections as undirected.

## Compile and run
With GCC installed:

```bash
gcc main.c -o file_search
./file_search
```

On Windows:

```bash
gcc main.c -o file_search.exe
file_search.exe
```

## Sample input
For the prompts, enter:

```text
5
root
Documents
Pictures
notes.txt
photo.jpg
4
root Documents
root Pictures
Documents notes.txt
Pictures photo.jpg
root
notes.txt
```

## Sample output (prompts omitted)
```text
BFS traversal: root Documents Pictures notes.txt photo.jpg
BFS result: File FOUND.
DFS traversal: root Documents notes.txt Pictures photo.jpg
DFS result: File FOUND.
```

Traversal order can vary if the order of nodes or edges is changed.

## Complexity
- BFS: O(V^2) with an adjacency matrix.
- DFS: O(V^2) with an adjacency matrix.
- Space: O(V^2) for the adjacency matrix, plus O(V) traversal storage.

## Repository contents
- `main.c` — C source code
- `README.md` — instructions and sample run
