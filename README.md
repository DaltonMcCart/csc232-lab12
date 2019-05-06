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

We always start the game in the first column and have two types of moves.