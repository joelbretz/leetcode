class Solution {
  protected:
  public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int curr = 0, high = 0;
    sort(tokens.begin(), tokens.end());
    int left = 0, right = tokens.size() - 1;
    while(left <= right && (power >= tokens[left] || curr > 0)) {
      // gobble em up
      while(left <= right && power >= tokens[left]) {
        power -= tokens[left];
        left++;
        curr++;
      }

      high = max(high, curr);
      if(left <= right && curr > 0) {
        power += tokens[right];
        right--; curr--;
      }
    }
    return high;
  }
};
