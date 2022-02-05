$include Stack.h
// pop two items off of the stack, add them and push the result on the stack
$def add
// Pop value from stack into D
@SP
M=M+1
A=M
D=M
// Set A to the top of stack
A=A+1
// Add D to top of stack
M=D+M
$end
// pop two items off of the stack and subtract them, push result onto stack
$def sub
// Pop first item off of stack into D
@SP
M=M+1
A=M
D=M
// Set A to top of stack
A=A+1
// Subtract D off of top of stack
M=M-D
$end
// Pop the top of the stack and push its bitwise complement on the stack
$def not
// Compute address of top of stack
@SP
A=M+1
// bitwise complement top of stack
M=!M
$end
// Pop the top of the stack and push its negation on the stack
$def neg
// Compute address of top of stack
@SP
A=M+1
// negate top of stack
M=-M
$end
// comparison operators
// pop two elements of off the stack and push -1 if they are equal, 0 otherwise
$def eq
// Pop top of stack into D
@SP
M=M+1
A=M
D=M
A=A+1
D=M-D
// D is zero if equal
// if equal skip to set D=-1
@SKIP
D;JEQ
D=-1
(SKIP)
// D is set for not equal, do bitwise complemetn
D=!D
// save D to top of stack
@SP
A=M+1
M=D
$end
// Pop a, pop b if b<a push -1 else push 0
$def lt
// Pop top of stack into D
@SP
M=M+1
A=M
D=M
@R15
M=D // save for later
@0x7fff
A=!A
D=D&A
@SP
A=M+1
D=D+M // negative D means arguments have opposite sines
@SKIP2
D;JGE
// now we have code that determines gt based on sign only
@R15
D=M
@NEGATIVE1
D;JLT
D=-1
@SKIP
0;JMP
(NEGATIVE1)
D=0
@SKIP
0;JMP
(SKIP2)
@R15
D=M
@SP
A=M+1
D=M-D
@LESSTHAN
D;JLT
D=0
@SKIP
0;JMP
(LESSTHAN)
D=-1
(SKIP)
// save D to top of stack
@SP
A=M+1
M=D
$end
// Pop a, pop b if b>a push -1 else push 0
$def gt
// Pop top of stack into D
@SP
M=M+1
A=M // A contains SP
D=M
@R15
M=D // save for later
@0x7fff
A=!A
D=D&A
@SP
A=M+1
D=D+M // negative D means arguments have opposite signs
@SKIP2
D;JGE
// now we have code that determines gt based on sign only
@R15
D=M
@NEGATIVE1
D;JLT
D=0
@SKIP
0;JMP
(NEGATIVE1)
D=-1
@SKIP
0;JMP
(SKIP2)
@R15
D=M
@SP
A=M+1
D=M-D
@GREATERTHAN
D;JGT
D=0
@SKIP
0;JMP
(GREATERTHAN)
D=-1
(SKIP)
// save D to top of stack
@SP
A=M+1
M=D
$end
// pop two values of the stack and push their bitwise and
$def and
// Pop value from stack into D
@SP
M=M+1
A=M
D=M
// Set A to the top of stack
A=A+1
// Add D to top of stack
M=D&M
$end
// pop a, pop b, push a|b
$def or
// Pop value from stack into D
@SP
M=M+1
A=M
D=M
// Set A to the top of stack
A=A+1
// Add D to top of stack
M=D|M
$end
// Go into infinite loop
$def halt
@HALT
(HALT)
0;JMP
$end
