class Solution {
  protected:
  void createSentences(vector<string>& solution, string& cur, int nopen, int nclose, int max) {
    if(cur.length() == (max << 0x1)) {
      solution.push_back(cur);
      return; 
    }

    if(nopen < max) {
      cur += '(';
      createSentences(solution, cur, nopen + 1, nclose, max);
      cur.pop_back();
    }
    if(nclose < nopen) {
      cur += ')';
      createSentences(solution, cur, nopen, nclose + 1, max);
      cur.pop_back();
    }

  }

  public:
  vector<string> generateParenthesis(int n) {
    vector<string> sentences;
    string curr;
    createSentences(sentences, curr, 0, 0, n);
    return sentences;
  }
};
