#include <iostream>
using namespace std ;

int lt(int v) {
  if(v<0) return -1 ;
  else return 0 ;
}

int main() {
  // example of overflow with 16bit twos complement subtraction

  {
    short a = 32767 ;
    short b = 32765 ;
    short c = -2 ;

    short ab = (a-b) ;
    short bc = (b-c) ;
    short ac = (a-c) ;
  
    cout << " 16 bit comparison of a=" << a << ", b=" << b << ", c=" << c <<endl ;
    cout << "a-b=" << ab <<", lt(a,b)=" << lt(ab) << ", a<b=" << (a<b)
	 << " b-c=" << bc << ", lt(b,c)=" << lt(bc) << ", b<c=" << (b<c)
	 << " a-c="<< ac << ", lt=(a,c)=" << lt(ac)<< ", a<c=" << (a<c) <<endl ;
  }
  
  int a = 32767 ;
  int b = 32765 ;
  int c = -2 ;

  int ab = (a-b) ;
  int bc = (b-c) ;
  int ac = (a-c) ;
  
  cout << " 32 bit comparison of a=" << a << ", b=" << b << ", c=" << c <<endl ;
    cout << "a-b=" << ab <<", lt(a,b)=" << lt(ab)
	 << " b-c=" << bc << ", lt(b,c)=" << lt(bc)
	 << " a-c="<< ac << ", lt=(a,c)=" << lt(ac)<< endl ;

  return 0 ;
}
