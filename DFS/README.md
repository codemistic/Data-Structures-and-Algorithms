# Depth-First Search (DFS)

## What is DFS?

**Depth-First Search (DFS)** is a graph and tree traversal algorithm that explores as far as possible along one path before backtracking and exploring another path.

DFS can be implemented using:

* **Recursion**
* **Stack**

## How DFS Works

1. Start from a node.
2. Mark the node as visited.
3. Visit one of its unvisited neighbors.
4. Continue going deeper until there are no unvisited neighbors.
5. Backtrack and explore other paths.

### Example

For the graph:

```text
    A
   / \
  B   C
 / \
D   E
```

A possible DFS traversal is:

```text
A → B → D → E → C
```

## DFS in Word Search

In the **Word Search** problem, DFS is used to explore neighboring cells to find the given word.

From each cell, we can move in four directions:

```text
      Up
       ↑
Left ← Cell → Right
       ↓
     Down
```

A cell is temporarily marked as visited so that it is not used twice in the same path. After exploring the path, the cell is restored. This process is called **backtracking**.

## Algorithm

```text
For every cell in the board:
    Start DFS

DFS(row, col, index):
    If the complete word is found:
        return true

    If the cell is invalid or doesn't match:
        return false

    Mark the cell as visited

    Search:
        Up
        Down
        Left
        Right

    Restore the cell

    Return whether any direction found the word
```

## Complexity

For a graph with `V` vertices and `E` edges:

* **Time:** `O(V + E)`
* **Space:** `O(V)`

For the Word Search problem, the worst-case time complexity is approximately:

`O(m × n × 4^L)`

where:

* `m × n` = board size
* `L` = length of the word

## Applications

DFS is commonly used for:

* Graph and tree traversal
* Finding connected components
* Cycle detection
* Maze solving
* Path finding
* Topological sorting
* Backtracking problems
* Word Search

## Implementation

The C++ implementation for Word Search is provided in `word_search.cpp`.
