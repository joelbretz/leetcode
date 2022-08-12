class Solution {
  public:
  
  int chalkReplacer(vector<int>& chalk, int k) {
    long sum = 0;
    // determine the amount of chalk needed for each loop.
    for(int x: chalk)
      sum += x;
    // reduce the number of pieces of chalk to remainder
    k %= sum;
    // now just iterate once and see where we run out.
    for(int i = 0; i < chalk.size(); i++)
      if((k-=chalk[i]) < 0)
        return i;
    return 0;
  }
  
  // obvious solution: TLE for [1] 10000000
  int chalkReplacerTLE(vector<int>& chalk, int k) {
    int i = 0;
    while(k >= 0) {
      //cout << "i: " << i << ", k: " << k << endl;
      if( k < chalk[i])
        return i;
      k -= chalk[i];
      i++;
      if(i >= chalk.size())
        i -= chalk.size();
    }
    return -1;
  }
};
