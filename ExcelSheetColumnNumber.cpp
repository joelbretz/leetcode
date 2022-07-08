class Solution {
  public:
  int titleToNumber(string columnTitle) {
    long col = 0, mult = 1;
    for(int i = columnTitle.size() - 1; i >= 0; --i) {
      col += (columnTitle[i] - 'A' + 1) * mult;
      mult *= 26;
    }
    return col ;
  }
};
