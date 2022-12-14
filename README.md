# monty
# 0x19. C - Stacks, Queues - LIFO, FIFO
## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

# General
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
# Requirements
## General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called monty.h
- Don’t forget to push your header file
- All your header files should be include guarded
- You are expected to do the tasks in the order shown in the project
---

## Instructions
Compile with:
```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
---
## Example

![demo](https://puu.sh/CksXw/b90dd61cb5.png)

## Files

### [monty.c](./monty.c)
* Contains the main function that takes in the file and runs the parser.

### [monty.h](./monty.h)
* Header file.

### [parse.c](./parse.c)
* Functions that parses the file from main, then parses the lines. While parsing, data is stored into structs to be passed onto other functions.

### [verify.c](./verify.c)
* Contains functions that checks arguments from lines of the file. Checks for if push function is in the file line.

### [match.c](./match.c)
* Our get operations function that matches the aruguments with what opcode function we need to run.

### [opcodes_1.c](./opcodes_1.c)
* Contains push, pall, free_stack, and nop.

### [opcodes_2.c](./opcodes_2.c)
* Contains pint, pop, swap, pchar, and pstr.

### [opcodes_3.c](./opcodes_3.c)
* Contains rotl, rotr, qpush.

### [opcodes_math.c](./opcodes_math.c)
* Contains add, sub, div, mul, mod.

### [opcodes_mode.c](./opcodes_mode.c)
* Contains stack and queue.

---
## Requirements
- All your files will be compiled on Ubuntu 14.04 LTS
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The repository monty should be added as a submodule to your holbertonschool-low_level_programming repository, under the name 0x18-stacks_queues_lifo_fifo

---

## Tasks

### 0. push, pall
* Implement the push and pall opcodes.
* The opcode push pushes an element to the stack.
* The opcode pall prints all the values on the stack, starting from the top of the stack.

### 1. pint
* Implement the pint opcode.
* The opcode pint prints the value at the top of the stack, followed by a new line.

### 2. pop
* Implement the pop opcode.
* The opcode pop removes the top element of the stack.

### 3. swap
* Implement the swap opcode
* The opcode swap swaps the top two elements of the stack.

### 4. add
* Implement the add opcode.
* The opcode add adds the top two elements of the stack.

### 5. nop
* Implement the nop opcode.
* The opcode nop doesn’t do anything.

### Advanced Tasks
* opcodes: sub, div, mul, mod, comments, pchar, pstr, rotl, rotr, stack, queue, Holberton, Add two digits, Multiplication, Multiplication level up

---
## Author
* **Araromi, Dauda Olurotimi ** - [daudaararomi](https://github.com/daudaararomi]
