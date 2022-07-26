class Solution {
  public:
  // revert the second half and compare values
  bool isPalindrome(int x) {
    // negatives are not palindromes
    if(x < 0)
      return false;
    // the only palindrome ending in 0 is zero
    if(x % 10 == 0 && x != 0) 
      return false;
    
    int reverted = 0;
    // we have reverted half when reverted >= x
    while(x > reverted) {
      reverted = (reverted * 10) + (x % 10);
      x /= 10;
    }
    // even length palindrome numbers:
    if (x == reverted)
      return true;
    
    // odd length eg. 69396 -> x = 69 reverted = 693
    if(x == reverted/10)
      return true;
    
    return false;
  }
  
  // to_string solution, then 2 pointers
  bool isPalindromeObvious(int x) {
    string s = to_string(x);
    int left = 0, right = s.length() - 1;
    while(left <= right) {
      if(s[left] != s[right])
        return false;
      left++; right--;
    }
    return true;
  }
};
