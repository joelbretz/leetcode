class Solution {
  public:
  // digit access in cpp sucks.
  // overly complicated solution with % and n /= 10
  int subtractProductAndSum(int n) {
    int p = 1, s = 0, v;
    while(n) {
      v = n % 10;  
      p *= v; 
      s += v;
      n /= 10;
    }
    return p - s;
  }
};
