
load isortTest.hack,
output-file isortTest.out,
compare-to isortTest.cmp,
output-list RAM[0]%D2.6.2 RAM[8]%D2.6.2 RAM[32]%D2.6.2 RAM[33]%D2.6.2 RAM[34]%D2.6.2 RAM[35]%D2.6.2 RAM[36]%D2.6.2 RAM[37]%D2.6.2 RAM[38]%D2.6.2 RAM[39]%D2.6.2 RAM[40]%D2.6.2  RAM[41]%D2.6.2 RAM[42]%D2.6.2 RAM[43]%D2.6.2 RAM[44]%D2.6.2 RAM[45]%D2.6.2 RAM[46]%D2.6.2 RAM[47]%D2.6.2 ;

set RAM[0] 1023,
set RAM[1] 0,
set RAM[6] 32,
set RAM[7] 48,
set RAM[8] 0,
set RAM[32] 1,
set RAM[33] 12,
set RAM[34] -1,
set RAM[35] 5,
set RAM[36] 15,
set RAM[37] 13,
set RAM[38] 5,
set RAM[39] 2,
set RAM[40] 11,
set RAM[41] 10,
set RAM[42] 6,
set RAM[43] 3,
set RAM[44] 5,
set RAM[45] 3,
set RAM[46] 7,
set RAM[47] 7,

repeat 100000 {
  ticktock;
}
output;

set PC 0,
set RAM[6] 32,
set RAM[7] 36,
set RAM[8] 0,
set RAM[32] 1,
set RAM[33] 1,
set RAM[34] 1,
set RAM[35] 1,
set RAM[36] 0,
set RAM[37] 0,
set RAM[38] 0,
set RAM[39] 0,
set RAM[40] 0,
set RAM[41] 0,
set RAM[42] 0,
set RAM[43] 0,
set RAM[44] 0,
set RAM[45] 0,
set RAM[46] 0,
set RAM[47] 0,

repeat 10000 {
   ticktock ;
}
output;

set PC 0,
set RAM[6] 32,
set RAM[7] 36,
set RAM[8] 0,
set RAM[32] 5,
set RAM[33] 5,
set RAM[34] 5,
set RAM[35] 1,

repeat 10000 {
   ticktock ;
}
output;


