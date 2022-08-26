class Solution {
  public:
  // old skool k&r solution bitwise & n and n -1 :
  int rangeBitwiseAnd(int left, int right) {
    while(left < right) {
      right = right & (right - 1);
    }
    return left & right;
  }
};
