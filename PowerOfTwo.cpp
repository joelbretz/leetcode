/*
How to get / isolate the rightmost 1-bit : x & (-x).
How to turn off (= set to 0) the rightmost 1-bit : x & (x - 1).
*/

class Solution {
  public:
  bool isPowerOfTwo(int n) {
    if(n==0)
      return false;
    long v = (long) n;
    return (v & (-v)) == v;
  }
};

