class Solution {
public:
    // obvious solution:
    // a. count letters. 
    // b. return the index of the first letter in s whose count == 1
    int firstUniqChar(string s) {
        //map<char,int> letterCount;
        vector letterCount(26,0);
      for(int i = 0; i < s.length(); ++i) {
        letterCount[s[i] - 'a']++;
      }
      for(int i = 0; i < s.length(); ++i) {
        if(letterCount[s[i] - 'a'] == 1)
          return i;
      }
      return -1;
    }
};
