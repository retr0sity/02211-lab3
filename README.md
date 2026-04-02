# 02211-lab3
## Brainf*ck CPU in ActSim
### Overview
This project implements a custom CPU in ActSim designed to execute programs written in Brainfuck. Brainfuck is a minimalist programming language consisting of only eight commands. It operates on a linear memory tape and a data pointer that traverses this tape. More about Brainfuck: https://en.wikipedia.org/wiki/Brainfuck

The CPU translates Brainfuck’s minimal instruction set into a set of 8 hardware-executable instructions, demonstrating how a simple programming language can be mapped onto a custom processor design.
### Commands

| Command | Description |
|--------|------------|
| `>` | Increment the data pointer (move right) |
| `<` | Decrement the data pointer (move left; undefined at position 0) |
| `+` | Increment the byte at the data pointer (modulo 256) |
| `-` | Decrement the byte at the data pointer (modulo 256) |
| `.` | Output the byte at the data pointer |
| `,` | Read one byte of input into the current cell |
| `[` | If current cell is 0, jump forward to matching `]` |
| `]` | If current cell is nonzero, jump back to matching `[` |

#### Example Code
```brainfuck
+++++ [ > +++++ < - ] > .
```

Initializes a number, squares it, and outputs it.  
**Output:** `25`

### How to run:
1. Update actflow path in testXXXX.sh file
   
```bash
export ACT_HOME=$HOME/act-local
export PATH=$PATH:$ACT_HOME/bin
```

2. Run the testscript testXXXX.sh 

```
 bash ./testCPU.sh
 bash ./testmul.sh
```

3. Execute the simulation script in ActSim:

```
 source testCPU.scr
```

### Authors
Leo Moe - s251885

Kunal Gurudath Athikary - s252718 

Ioannis Karkalas - s260194

Arjun Babu Anand - s252759


### References
Brainfuck specification and documentation - https://en.wikipedia.org/wiki/Brainfuck


### How it works. 
There are 2 main components, the IM (Instruction Memory) and the CPU. A curious reader would notice that I didn't mention the data memory. 
The DM is an array inside of the CPU.
The instructions are not encoded as bytes, but instead as 3-bit codes, indicated by their position in the list on the wikipedia page.

The IM does a few things: 
    1. It initializes by loading in all the instructions from a component we have in the testscripts called the InitIM. 
        The IM knows it is done when an instruction over 7 is input. For this reason, we finish it by writing 8. 
    2. It sends instructions out to the CPU. 
        It does this through an output channel. At the end of init, it sends the instruction on ip (instructionpointer)=0. 
    3. It receives instructions from the CPU. 
        The IM will send instructions. 
        Brainfuck only has conditional branching instructions. 
        For this reason, the CPU needs to evaluate if the branch instruction actually is a branch instruction. 
        As such, the IM is told by the IM what to do.

The CPU does a few things. 
    1. For its main loop, it constantly waits for instructions from IM, executes it and sends back to IM what to do next. 
    2. For the main instructions, (<,>,+,-), it simply executes the instruction on either the datapointer or the value at the datapointer and then goes on with the day. 
    3. for the branching instructions, it evaluates the condition and send back to the IM.
    4. For the . and , it uses the channels to either input or output. These channels need to be supplied in the testbench. 
    
        