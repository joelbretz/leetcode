class Solution {
  public:
  // grab digits 1 by one and put them into solution.
  // multiply current by ten, then add the next digit.
  // check for overflow before calculating each step.
  // O(1) space O(log(x)) time
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
      if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
      rev = rev * 10 + pop;
    }
    return rev;
  }
};
