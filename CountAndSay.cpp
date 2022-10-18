class Solution {
  public:
  string countAndSay(int n) {
    string cur("1");
    for(int i = 2; i <= n; ++i) {
      string next;
      for(int j = 0, k = 0; j < cur.length(); j = k) {
        while(k < cur.length() && cur[k] == cur[j]) 
          ++k;
        next += to_string(k - j) + cur[j];
      }
      cur = next;
    }
    return cur;
  }
};
