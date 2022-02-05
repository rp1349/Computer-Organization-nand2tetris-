#include <iostream>
#include <algorithm>
using namespace std ;

// Lomuto partitioning scheme
short *partition(short *begin, short *end) {
  short pivot = *(end-1) ;
  short *i=begin-1 ;
  for(short *j=begin;j<end;++j) {
    if(*j <= pivot) {
      i++ ;
      std::swap(*i,*j) ;
    }
  }
  return i ;
}

short qsort(short *begin, short *end) {
  short sz = end-begin ;
  short *split ;
  if(sz < 2)
    return sz ;
  split = partition(begin,end) ;
  qsort(begin,split) ;
  qsort(split,end) ;
  return sz;
}


// insertion sort
short isort (short *begin, short *end) {
  short *i = begin ;
  short *j ;
  short x ;
  while(i<end) {
    x = *i ;
    j = i-1 ;
    while(j>=begin && *j>x) {
      *(j+1) = *j ;
      j=j-1 ;
    }
    *(j+1) = x ;
    i=i+1 ;
  }
  return end-begin ;
}
int main() {

  short A[] = { 5, 9, 1, 3, 7, 2, 6, 8, 4, 0,
		12,22,33,77,-1, -2, -3, -5, -6, -12} ;

  short *begin = &A[0] ;
  short *end = begin+sizeof(A)/sizeof(short) ;
  cout << "len =" << end - begin<< endl;
  cout << "A=" ;
  for(short *i=begin;i<end;++i)
    cout << " " << *i ;
  cout << endl ;
  short pivot = A[0] ;
  //  cout <<"partition, pivot = " << pivot << endl ;
  //  short *split = partition(begin,end,pivot) ;
  //  qsort(begin,end) ;
  short len = end-begin ;
  isort(begin,end) ;
  cout << "A=" ;
  for(short i=0;i<len;++i)
    cout << " " << A[i] ;
  cout << endl ;
  //  cout << "*split=" << *split << endl ;
  
}
