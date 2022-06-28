class Solution {
  public:
  int lengthOfLongestSubstring(string s) {

    if(!s.length())
      return 0;
    else if(s.length() == 1)
      return 1;

    unordered_map<char,int> letterPosition;
    int longest = 1;
    int start = 0, end = 1;
    letterPosition[s[0]] = 0;
    for(;end < s.length(); ++end) {
      // check if we've seen it before
      auto it = letterPosition.find(s[end]);
      if(it==letterPosition.end() || it->second < start) {
        // not found. (or skipped in a prev jump
        // add to hash, check length of string
        letterPosition[s[end]] = end;
        longest = max(longest,(end-start+1));
        //cout << "start=" << start << ", end=" << end ;
        //cout << ", substr = " << s.substr(start,end-start+1) << endl; 
      }
      else {
        // advance start of window to the char following the 
        // one we just found, update hash
        start = letterPosition[it->first] + 1;
        it->second = end;  
      }
    }
    return longest;
  }
};
