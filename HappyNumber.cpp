class Solution {
  public:

  int sumDigits(int n) {
    int lsb, sum = 0;
    while(n) {
      lsb = n % 10;
      n /= 10;
      sum += lsb * lsb;
      //cout << lsb << endl;
    }
    //cout << "sum of digits squared: " << sum << endl; 
    return sum;
  }

  bool isHappy(int n) {
     unordered_set<int> seen;
    while(n != 1 && (seen.find(n) == seen.end())) {
      seen.insert(n);
      n = sumDigits(n);
    } 
    return (n == 1);
  }
};
