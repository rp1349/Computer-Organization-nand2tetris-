$include Operators.h
$def procedureCall nargs procedure
// Push return address onto stack
@RETURN
$pushA
// Jump to procedure
@procedure
0;JMP
// Return here
(RETURN)
// Remove nargs-1 arguments off of the stack
@nargs
D=A-1
// Add D to SP to pop off consumed arguments
@SP
M=D+M
$end
// Return from procedure
$def return
// Pop return address off of stack and jump
$popAD
0;JMP
$end

$def pushFrame nargs nlocals
@LCL
D=M
$pushD
@ARG
D=M
$pushD
@THIS
D=M
$pushD
@THAT
D=M
$pushD
@SP
D=M
@LCL
M=D
@nargs
D=D+A
@5
D=D+A
@ARG
M=D
@nlocals
D=A
@SP
M=M-D
$end
$def popFrame nargs nlocals
// Restore SP to when stack frame was initialized
@LCL
D=M
@SP
M=D
// Pop THAT
$popAD
@THAT
M=D
// Pop THIS
$popAD
@THIS
M=D
// Pop ARG
$popAD
@ARG
M=D
// Pop LCL
$popAD
@LCL
M=D
$end
