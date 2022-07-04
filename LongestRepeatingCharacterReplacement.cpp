
class Solution {
  public:
  int characterReplacement(string s, int k) {
    
    vector<int> count(26,0); ///< letter counts (all CAPS)
    int left = 0, right = 0; ///< window indices
    int maxFreq = 0;  ///< count of most frequent character
    int longest = 0; ///< longest string of repeating chars
    
    // slide the window through s:  
    //   increment the count of the current letter
    //   update maxFreq if needed
    //   --> then check the window size and move the
    //       left edge if size - mostFreq > k
    for(; right < s.length(); ++right) {
      count[s[right]-'A']++;
      maxFreq = max(maxFreq, count[s[right]-'A']);
      if(right - left + 1 - maxFreq > k) {
        count[s[left]-'A']--;
        left++;
      }
      longest = max(longest, right-left+1);
    }
    return longest;
  }
};
