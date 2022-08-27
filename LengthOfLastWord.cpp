class Solution {
  public:
  int lengthOfLastWord(string s) {
    stringstream oss(s);
    string curr;
    oss >> curr; int len = 0;
    while(!oss.eof()) {
      //len = curr.length();
      oss >> curr;
    }
    len = curr.length();
    return len;
  }
};
