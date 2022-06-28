class Solution {
  public:
  // bsearch for it.
  // 
  int arrangeCoins(int n) {
    long left = 0, right = n, mid;
    while(left <= right) {
      mid = left + (right-left) / 2; //(left+right) / 2;
      auto sum = mid*(mid+1)/2;

      if(sum == n) return mid;

      if(sum < n)
        left = mid + 1;
      else
        right = mid - 1;
    }
    return (int)right;
  }

  // arithmetic sum: 1 + 2 + 3 + ... + n = n(n + 1) / 2
  // 2 * coins = n^2 + n --> n^2 + n - 2*coins = 0;
  // -b +- sqrt(b^2 - 4ac ) / 2a
  // --> fails for overflow for HUGE n. eg.  1804289383
  int arrangeCoinsQuadraticFormula(int n) {
    long long a = 1, b = 1, c = -2*n;

    double sol = (-1 + sqrt(1 - 4*1*c)) / 2;
    cout << floor(sol) ;
    return (floor(sol));   
  }
};
