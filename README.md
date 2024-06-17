# 42-push_swap

### Table of Contents
- [Introduction](#introduction)
- [Requirements](#Requirements)
- [How to use](#How-to-use)

### Introduction
This project is an introduction to DSA (data structures and algorithms).

The objective of this program is to sort a stack of integers only using 2 stacks, with the smallest number of moves, and a limited set of instructions. Following instructions should be used:

- ```sa``` (swap a): Swap the first 2 elements at the top of stack a.
- ```sb``` (swap b): Swap the first 2 elements at the top of stack b.
- ```ss```: Perform sa and sb simultaneously.
- ```pa``` (push a): Take the first element at the top of stack b and push it onto stack a.
- ```pb``` (push b): Take the first element at the top of stack a and push it onto stack b.
- ```ra``` (rotate a): Shift up all elements of stack a by 1.
- ```rb``` (rotate b): Shift up all elements of stack b by 1.
- ```rr```: Perform ra and rb simultaneously.
- ```rra``` (reverse rotate a): Shift down all elements of stack a by 1.
- ```rrb``` (reverse rotate b): Shift down all elements of stack b by 1.
- ```rrr```: Perform rra and rrb simultaneously.

To achieve this goal we have to decide on which sorting algorithm and what data structures to use. For my implementation I used the <a href="https://www.geeksforgeeks.org/radix-sort/">Radix Sort</a>. To manipluate the stacks I used <a href="https://www.geeksforgeeks.org/linked-list-data-structure/">Linked List</a>.  

### Requirements

**Arguments**: The program takes an array of positive or/and negative numbers.

**Output**: The program will display the smallest list of instructions on the stdout.

**Error handling**: In case of an error (input is not an integer, input has duplicates, etc.) an error message will be displayed. If there are no specified parameters, nothing will be displayed.

### How to use

To compile the project, use `make`. 

To run the project:

```shell
./push_swap <numbers>
```

Example:

```shell
./push_swap 23 2147483647 -2147483648 0 -21
```

The program can be validated with the provided checker:

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```
--- 
