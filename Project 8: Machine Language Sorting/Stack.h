// Note for this the stack will be starting at the top of memory and building
// down.  These are the basic stack operations that will be implemented

// Push D register onto the stack, D remains unchanged by ths operation
$def pushD
// Load SP into A
@SP
A=M
// Store D into *SP
M=D
// Decrement Stack pointer
@SP
M=M-1
$end
// Push A register onto the stack
$def pushA
// load At into D register
D=A
$pushD
$end
// Pop the top of stack into the A and D registers
$def popAD
// increment stack pointer
@SP
AM=M+1
// read top of stack into A and D
AD=M
$end
// get the local variable id defined by *(LCL-id) into registers A and D
$def getLocal id
@id
D=A
@LCL
A=M
A=A-D
AD=M
$end
// store register D in the local variable id defined by *(LCL-id)
$def setLocal id
// save D in R14 while we compute the address
@R14
M=D
// Compute address of local variable
@id
D=A
@LCL
A=M
D=A-D
// Save address in R15
@R15
M=D
// retrieve data from R14
@R14
D=M
// Store D in address contained in R15
@R15
A=M
M=D
$end
// get argument id (defined by *(ARG-id)) and store in registers A and D
$def getArgument id
// compute address of the argument
@id
D=A
@ARG
A=M
A=A-D
// Get argument into D register
AD=M
$end
// set the argument id (defined by *(ARG-id)) to the value stored in register D
$def setArgument id
@R14
M=D
// Compute address of argument
@id
D=A
@ARG
A=M
D=A-D
// Save address in R15
@R15
M=D
// retrive Data
@R14
D=M
// Load Address from R15
@R15
A=M
// Save data to argument
M=D
$end
// Use push value, push ptr, setPTR pops these off of stack and
// sets *ptr=value
$def setPTR
// pop ptr
$popAD
@R15
M=D
// pop value
$popAD
// implement *ptr =D  
@R15
A=M
M=D
$end
// get pointer pops pointer off of the stack then push *ptr onto the
// stack
$def getPTR
// pop ptr
$popAD
D=M
$pushD
$end
