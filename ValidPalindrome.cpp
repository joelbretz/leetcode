class Solution {
  public:
  
  // the straight forward solution:
  // 1st - create the possible palindrome string
  //  a. find alpha numeric or digits 
  //  b. push the on the string using tolower
  // 2nd - use a 2 pointer (left/right) to check for palindromw
  bool isPalindrome(string s) {

    string p ;
    for(auto c : s) {
      if(isalpha(c) || isdigit(c))
        p += tolower(c);
    }
    cout << p << endl;
    int left = 0, right = p.length() - 1;
    while(left <= right) {
      if(p[left] != p[right])
        return false;
      left++; right--;
    }
    return true;

  }
};
