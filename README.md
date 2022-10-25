# CPSC 323 Project 1: Table-Driven PL/0 Lexical Analyzer

## Group Members
Omar Trejo trejo.omar562@csu.fullerton.edu , 
Nathanael Kim nathan.kim@csu.fullerton.edu

## What do to

Your task is to finish the lexical analyzer implementation in `lexer.cpp`. You will need to create two tables: a scanning table and token table. The token table is a table of two columns that denotes the mapping between final states and the token type. Example: row 3 final state 4 accepts an IDENTIFIER (1). The scanning table is a DFSM transition table, with all $\sigma \in \Sigma$ as column values and the first column containing the machine states $q \in Q$ such that $table[q_{prev}][\sigma] = q_{next}$.

## How to build

Ensure you have a C/C++ compiler, make, and CMake installed. Executed the follow commands in terminal in the repository directory.

```
mkdir build
cd build
cmake ../
make
```

The resulting executables are populated within the build directory, which include `Compiler.out` and `Test.out`.

`Compiler.out` takes one argument, the file path of the file to perform the lexical analysis on. Because you are graded on the test cases, the `Compiler.out` driver is mainly for testing and debugging example code you will create.

```
./Compiler.out ../test/test_code/test1.p0
```

`Test.out` is executed without arguments.

```
./Test.out
```

Your code must pass all test cases, including withheld test cases, for full credit.
