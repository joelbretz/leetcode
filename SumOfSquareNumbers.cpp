class Solution {
  public:
  /*
  fermats theorem
  A postive integer n is representable as the sum of two squares, n=x2+y2 if and only if every prime divisor p≡3 mod 4 of n occurs with even exponent.
  */
  // not implemented. 


  //a2 + b2 = c2 --> b = sqrt(c2 - a2)
  bool judgeSquareSum(int c) {
    for (long a = 0; a * a <= c; a++) {
      double b = sqrt(c - a * a);
      if (b == (int) b)
        return true;
    }
    return false;
  }


  /*
  We can also have this problem in O(sqrt(n)) 
To solve this problem in sqrt(n) complexity, we use a hashmap where we will store the squares of numbers till sqrt(n), and each time we will search for (n – sqrt(i)) in the hashmap if it exists, then return Yes else return No.
  */
  bool judgeSquareSum2(int n) {
    //unordered_map<int,int> hash;
    unordered_map<int,int> hash;
    int limit = sqrt(n) + 1;
    for(int i = 1; i < limit; ++i) {
      hash[i*i] = 1; 
      if(hash.find(sqrt(n-i*i)) != hash.end() )
        return true;
    }
    return false;

  }
  // Brute Force, use of sqrt is allowed.
  // O(n^2) time, O(1) space
  bool judgeSquareSumBF(int c) {
    int n = sqrt(c) + 1;
    for(int i = 1; i < n; ++i) {
      for(int j = i; j < n; ++j) {
        if(i*i+j*j == c)
          return true;
      }
    }
    return false;
  }
};
