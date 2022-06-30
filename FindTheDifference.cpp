class Solution {
  public:
  // count letters:
  char findTheDifference(string s, string t) {
    vector<int> count (26,0);
    int sLen = s.length(); int tLen = t.length();
    for(int i = 0; i < sLen; ++i) {
      count[t[i] - 'a']++;
      count[s[i] - 'a']--;
    }
    count[t[tLen-1] - 'a']++;

    for(int i = 0; i < 26; ++i)
      if(count[i] != 0)
        return ('a' + i);
    
    return EOF;
  }
};
