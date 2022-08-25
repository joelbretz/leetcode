// notice:
// n, max prod
// 1   1
// 2   2
// 3   3
// 4   4  2x2
// 5   3 * 2 = 6
// 6   3 * 3 = 9
// 7   4 * 3 = 12
// 8   4 * 4 = 16
// 9   4 * 3 * 2 
// 10  4 * 3 * 3 


class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) 
          return n-1;
        else if(n == 4)
          return n;
        else if(n == 5) 
          return 6;
        else if (n == 6) 
          return 9;
        else return 3* integerBreak(n-3);
    }
};
