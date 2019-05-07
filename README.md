# Lab 12 - Dynamic Programming in C++

## Background

In this lab we shall explore concepts in _Dynamic Programming_ by implementing the **Jump It Game** discussed in class and in "_An Approach to Making Dynamic Programming Easier for Students in the Computer Science Curriculum_" by Saquer, Smith and Daehn.

As stated in the article:

The Jump It Game consists of a board with _n_ cells or columns. Each cell, except the first, contains a positive integer representing the cost to visit that cell. The first cell, where the game starts, always contains zero. A sample game board is shown below:

```text
+---+---+----+---+----+----+
| 0 | 5 | 75 | 7 | 43 | 11 |
+---+---+----+---+----+----+
```

We always start the game in the first column and have two types of moves. We can either move to the adjacent column or jump over the adjacent column to land two columns over. The cost of the game is the sum of the costs of the visited columns. The objective of the game is to reach the last cell with the lowest cost.

In the board shown above, there are several ways to get to the end. Starting in the first column, the cost so far is 0. One could jump to 75, then jump to 43, and then move to 11 for total of 75 + 43 + 11 = 129. However, a lower-cost path would be to move to 5, jump to 7, then jump to 11, for a total cost of 5 + 7 + 11 = 23. We want to write a solution that computes the cheapest cost for a game board represented as an array (vector).

As discussed in class, a naive recursive solution to this problem is (as shown in Python):

```python
def jumpIt(board):
    # board - list representing playing board
    if len(board) == 1:
        # if board contains exactly 1 cell
        return board[0]
    elif len(board) == 2:
        # if board contains exactly 2 cells then must move to adjacent cell
        return board[0] + board[1]
    elif len(board) == 3:
        # if board contains exactly three cells, it is cheaper to jump over
        return board[0] + board[2]
    else:
        # find lowest cost if next move is to move to adjacent cell
        cost1 = board[0] + jumpIt(board[1:])
        # find lowest cost if next move is to jump over adjacent cell
        cost2 = board[0] + jumpIt(board[2:])
        if cost1 < cost2:
            return cost1
        else:
            return cost2
```

To get a DP solution from the recursive solution, one should first write a recurrence equation that shows how the problem is solved in terms of smaller versions of itself. The recursive part in the `jumpIt` function gives us the equation we want:

```python
jumpIt(i) = min{board[i] + jumpIt(board[i + 1:]), board[i] + jumpIt(board[i + 2:])}
          = board[i] + min{jumpIt(board[i + 1:]), jumpIt(board[i + 2:])}
```

This says that the lowest cost for playing the game starting at cell `i` is the cost for visiting cell `i` plus the minimum of the lowest costs of playing the game by moving to the adjacent cell or by jumping one cell over. Now, we can use a table (i.e., a `map`) to cache solutions to sub-problems and follow a bottom-up approach to reach a DP solution as is shown in the following Python implementation:

```python
cost = [] # cache table to store solutions to sub-problems
def jumpIt(board):
    # DP solution
    # board - list with costs associated with visiting each cell
    n = len(board)
    # store cost if starting game at last cell
    cost[n - 1] = board[n - 1]
    # store cost if starting at cell before last cell
    cost[n - 2] = board[n - 2] + board[n - 1]
    # now fill in the rest of the table
    for i in range(n - 3, -1, -1):
        cost[i] = board[i] + min(cost[i + 1], cost[i + 2])
    # cost of playing game starting at first cell is stored at index 0
    return cost[0]
```

A top-down DP solution to the Jump It problem is not hard and is shown below in Python.

```python
cost = {} # dictionary/table for caching solutions to sub-problems
def topDownJumpIt(board, i):
    n = len(board)
    # If value is not in cache table
    if cost.get(i, None) == None:
        # Calculate value and cache it
        if i == n - 1:
            cost[i] = board[n - 1]
        elif i == n - 2:
            cost[i] = board[n - 2] + board[n - 1]
        else:
            # board length >= 3
            # find cost if next move is into adjacent cell
            cost1 = topDownJumpIt(board, i + 1)
            # find cost if next move is to jump over adjacent cell
            cost2 = topDownJumpIt(board, i + 2)
            cost[i] = board[i] + min(cost1, cost2)
    return cost[i]
```

## Tasks

Your job, in this lab, is to use the above Python code as inspiration for writing the code segments called for in 
[JumpItGame.cpp](JumpItGame.cpp). Ultimately, when running the `lab12` target, your output should look like:

```text
Default game score: 23

Playing game boards from file (using memoization)
Game 1 score: 23
Game 2 score: 0
Game 3 score: 5
Game 4 score: 75

Playing game boards from file (using tabulation)
Game 1 score: 23
Game 2 score: 0
Game 3 score: 5
Game 4 score: 75

Process finished with exit code 0
```

## Submission Details

Attach your completed `JumpItGame.cpp` file the the Teams assignment by the end of the day.

Grading rubric:
1 point for on-time submission
1 point for correct implementation of bottom-up solution
1 point for correct implementation of top-down solution