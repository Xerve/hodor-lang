# Hodor
A language for Hodor

Hodor is a brainfuck implementation designed so someone only knowing 
how to say the word "Hodor" would be able to code. For more about 
Brainfuck, see http://en.wikipedia.org/wiki/Brainfuck

## Syntax

*Hodor*    | *Function*
---------- | ----------
hodorHODOR | Increment the data pointer
hodorhodor | Decrement the data pointer
HODORHODOR | Increment the value at the data pointer
HODORhodor | Decrement the value at the data pointer
HODOR!     | Print the value at the data pointer
HODOR?     | Receive the value for the data pointer through STDIN
hodor?     | Equivelent to '[' in Brainfuck
hodor!     | Equivelent to ']' in Brainfuck

## Building Hodor

To build, you will need make and gcc. Simply run 

    make
    
## Running Hodor

To run a file, use

    ./hodor --hodor hodor/hodor.hodor
    
To run a string, use

    ./hodor "HODORHODOR HODOR! HODOR? HODOR!"
