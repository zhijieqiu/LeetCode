//Next higher number with same number of set bits
/*
When we observe the binary sequence from 0 to 2n – 1 (n is # of bits), 
right most bits (least significant) vary rapidly than left most bits. 
The idea is to find right most string of 1’s in x, and shift the pattern to right extreme, 
except the left most bit in the pattern. 
Shift the left most bit in the pattern (omitted bit) to left part of x by one position. An example makes it more clear,
x = 156
10
x = 10011100
(2)
10011100
00011100 - right most string of 1's in x
00000011 - right shifted pattern except left most bit ------> [A]
00010000 - isolated left most bit of right most 1's pattern
00100000 - shiftleft-ed the isolated bit by one position ------> [B]
10000000 - left part of x, excluding right most 1's pattern ------> [C]
10100000 - add B and C (OR operation) ------> [D]
10100011 - add A and D which is required number 163
*/
#include<iostream>
 
using namespace std;
typedef unsigned int uint_t;
// this function returns next higher number with same number of set bits as x.
uint_t snoob(uint_t x)
{
 
  uint_t rightOne;
  uint_t nextHigherOneBit;
  uint_t rightOnesPattern;
 
  uint_t next = 0;
 
  if(x)
  {
 
    // right most set bit
    rightOne = x & -(signed)x;
 
    // reset the pattern and set next higher bit
    // left part of x will be here
    nextHigherOneBit = x + rightOne;
 
    // nextHigherOneBit is now part [D] of the above explanation.
 
    // isolate the pattern
    rightOnesPattern = x ^ nextHigherOneBit;
 
    // right adjust pattern
    rightOnesPattern = (rightOnesPattern)/rightOne;
 
    // correction factor
    rightOnesPattern >>= 2;
 
    // rightOnesPattern is now part [A] of the above explanation.
 
    // integrate new pattern (Add [D] and [A])
    next = nextHigherOneBit | rightOnesPattern;
  }
 
  return next;
}
 
int main()
{
  int x = 156;
  cout<<"Next higher number with same number of set bits is "<<snoob(x);
 
  getchar();
  return 0;
}
