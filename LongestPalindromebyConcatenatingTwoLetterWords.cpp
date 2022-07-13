
class Solution {
  public:
  int longestPalindrome(vector<string>& words) {
    //cout << "------------------------" << endl;
    map<string,int> wordCount;
    //deque<string> palindrome;
    int longest = 0;
    for(auto s : words) {
      //increment the number of times we've seen this

      // check if my opposite exists
      char u = s[0];
      char v = s[1];
      string opposite = {v, u};
      if(wordCount[opposite] > 0) {
        longest += 4;
        wordCount[opposite]--;
      }
      else {
        wordCount[s]++;
      }
    }
    // check for doubles
    for(auto s : words) {
      if(s[0] != s[1])
        continue;
      else if (wordCount[s]) {
        longest += 2;
        break;
      }
    }
    return longest;
  }
};

