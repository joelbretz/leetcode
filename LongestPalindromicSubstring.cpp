class Solution {

  protected:
  int expand(string s, int left, int right) {
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
      --left; ++right;
    }
    return right - left - 1;
  }

  public:
  string longestPalindrome(string s) {

    int n = s.length();
    if(n < 2)
      return s;
    // keep track of indices in s where the longest starts and ends.
    int start = 0, end = 0;
    // we are going to scan right and expand left and right
    for(int i = 0; i < s.length(); ++ i) {
      int lenOdd  = expand(s, i, i);
      int lenEven = expand(s, i, i + 1);
      int len = max(lenOdd, lenEven);
      if(len > (end-start)) {
        start = i - (len-1)/2;
        end = i + len/2;
      }
    }
    return s.substr(start, (end-start)+1);
  }
};
