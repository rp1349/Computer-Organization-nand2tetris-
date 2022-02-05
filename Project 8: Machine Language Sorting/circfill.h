// Fill in screen with circles
//
// Screen Layout
//
// Pixel Layout: 512 columns by 256 rows
// Each word of screen memory provides pixel values for 16 consecutive pixels
// on the given row.  Each 32 16-bit words forms one row of 512 pixels.
//
// To fill the screen with diagonal lines we will compute a pixel as black or
// white if it satisfies the equation
//
//    (row+col)%m == k  where k<m and m is chosen to be a perfect power of 2
//
// This equation is known as the Diophantine equation and specifies an infinite
// family of lines with the sames slope.
//
// The basic pseudo code for this method is going to be
//
// for(int row=0;row<255;++row)
//   for(int col=0;col<512;++col)
//     if(((row-128)^2+(col-256(^2)%1024 < 512)
//        setPixel(row,col,BLACK)
//     else
//        setPixel(row,col,WHITE)
//
// Some complications, The pixel will be at a an address in the screen memory
// that is computed by addr=SCREEN+(row*32+(col/16)) and the bit will be given
// by bit = 2^(col%16).  Note that doing division calculations on the hack
// architecture will be slow, so we will instead keep up with the bit and
// address to access the pixel as we are iterating.  bit=1 will be setup at
// the start and each time we increment col, the bit will double.  The address
// will also be initialized to point to the start of screen memory and
// everytime bit reaches the max bit, bit will be reset to 1 and addr will be
// incremented.
//
// Updated Pseudo Code
//
// addr = SCREEN
// row2 = 16384 // (row-127)^2, row=0
// for(row=0;row<256;++row) {
//   bit = 1 ; // set bit to the first pixel location in the first word
//   col2 = 0 ; // (col-256)^2, col-9
//   for(col=0;col<512;++col) {
//     if((row2+col2)%1024 < 512)
//       *addr = *addr | bit ; // set pixel BLACK
//     // assume pixels initially zero , so no else needed
//     // now update bit by multiplying by 2
//     bit=bit+bit
//     if(bit==0) {  // bit becomes zero after overflowing 16 bits
//       bit = 1 ;   // reset bit to beginning of next word
//       addr = addr + 1 ; // advance to next word in screen
//     }
//     col2 = col2 + 2*(col-256)+1
//   } // end for col
//     row2 = row2 + 2*(row-128)+1
// } // end for row
// set stack pointer to end of RAM
//
// Code starts here
// addr = SCREEN
(DRAWSCREEN)
@SCREEN
D=A
@addr
M=D
@16384
D=A
@row2
M=D
// for(row=0;row<256;++row) {
@row
M=0
(ROWLOOP)
@256
D=A
@row
D=M-D
@EXITROWLOOP
D;JGE
//   bit = 1 ; // set bit to the first pixel location in the first word
@bit
M=1
@col2
M=0
//   for(col=0;col<512;++col) {
@col
M=0
(COLLOOP)
@512
D=A
@col
D=M-D
@EXITCOLLOOP
D;JGE
//     if((row2+col2)%1024 < 512) {
@row2
D=M
@col2
D=D+M
@1023
D=D&A
@511
D=D-A
@SKIPIF1
D;JGE
//       *addr = *addr | bit ; // set pixel BLACK
@bit
D=M
@addr
A=M // This implements *
M=D|M
//}
(SKIPIF1)
//     // assume pixels initially zero , so no else needed
//     // now update bit by multiplying by 2
//     bit=bit+bit
@bit
D=M
DM=D+M  //Update both bit and D
//     if(bit==0) {  // bit becomes zero after overflowing 16 bits
@SKIPIF2
D;JNE
//       bit = 1 ;   // reset bit to beginning of next word
@bit
M=1
//       addr = addr + 1 ; // advance to next word in screen
@addr
M=M+1
//     }
(SKIPIF2)
//   } // end for col
@col
D=M
@256
D=D-A
@col2
M=D+M
M=D+M
M=M+1
@col
M=M+1
@COLLOOP
0;JMP
(EXITCOLLOOP)
// } // end for row
@row
D=M
@128
D=D-A
@row2
M=D+M
M=D+M
M=M+1
@row
M=M+1
@ROWLOOP
0;JMP
(EXITROWLOOP)
$return
