class Solution {
  public:
  
  // use the known bsearch algorithm for integer math.
  bool isPerfectSquare(int num) {
    if (num < 0) 
      return false;
    if (num == 1) 
      return true;
    
    int i = 2;
    int j = num;
    while (i <= j) {
      long  k = i + (j - i) / 2; // avoid integer overflow
      if (k * k == num) 
        return true;
      if (k * k > num) {
        j = k - 1;
      } else {
        i = k + 1;
      }
    }
    return false;
  }
};
