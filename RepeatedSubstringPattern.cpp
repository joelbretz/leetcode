class Solution {
  public:
  bool repeatedSubstringPattern(string s) {
    int n = s.length();
    vector<int> dp(n, 0);
    // Construct partial match table (lookup table).
    // It stores the length of the proper prefix that is also a proper suffix.
    // ex. ababa --> [0, 0, 1, 2, 1]
    // ab --> the length of common prefix / suffix = 0
    // aba --> the length of common prefix / suffix = 1
    // abab --> the length of common prefix / suffix = 2
    // ababa --> the length of common prefix / suffix = 1
    for (int i = 1; i < n; ++i) {
      int j = dp[i - 1];
      while (j > 0 && s[i] != s[j]) {
        j = dp[j - 1];    
      }
      if (s[i] == s[j]) {
        ++j;
      }
      dp[i] = j;    
    }

    int l = dp[n - 1];
    // check if it's repeated pattern string
    return l != 0 && l % (n - l) == 0;
  }
};
