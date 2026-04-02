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

`
 ./testCPU.sh
`

3. Execute the simulation script in ActSim:

`
 source testCPU.scr
`

### Authors
Leo Moe - s251885

Kunal Gurudath Athikary - s252718 

Ioannis Karkalas - s260194

Arjun Babu Anand - s252759


### References
Brainfuck specification and documentation - https://en.wikipedia.org/wiki/Brainfuck
