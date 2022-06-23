class Solution {
  public:
  int hammingWeight(uint32_t n) {
    // ol' skool k&r solution.
    int bits = 0;
    while(n) {
      n &= (n-1);
      bits += 1;
    }
    return bits;
  }
};
