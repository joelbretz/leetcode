class Solution {
public:
    // in place, non recursive 2 pointer O(n) time, O(1) space
    void reverseString(vector<char>& s) {
        int a = 0, b = s.size() - 1;
      while(a < b) {
        swap(s[a++], s[b--]);
      }
    }
};
