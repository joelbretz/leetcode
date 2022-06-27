class Solution {
  public:
  int longestPalindrome(string s) {
    unordered_map<char,int> letterCount;
    for(auto c : s) {
      letterCount[c]++;
    }
    // count up number of letters, can only use 1 single.
    int len = 0, odd = 0;
    for(auto lc : letterCount) {
      if(lc.second % 2 == 0) {
        len += lc.second;
      }
      else {
        len += lc.second & 0xfffffffe; // lc.second & lc.second - 1;
        odd = 1;
      }
    }
    return len + odd;
  }

};
