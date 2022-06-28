class Solution {
  public:
  // 1st thought, sort em and compare.
  // O(nlogn) in time. (dependent on sort implementation. O(1) space.
  bool isAnagramSort(string s, string t) {
    if(t.length() != s.length())
      return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return (s == t);
  }

  // maintain count of letters.
  // count of letters at the end should be zero
  // O(n) time, single pass through s & t, plus <= 26 comparisons. O(1) space
  bool isAnagram(string s, string t) {
    if(t.length() != s.length())
      return false;

    vector<int> counts(26,0);
    for(int i = 0; i < s.length(); ++i) {
      counts[s[i] - 'a'] += 1;
      counts[t[i] - 'a'] -= 1;
    }
    for(auto n : counts) {
      if(n != 0)
        return false;
    }
    return true;
  }

};
