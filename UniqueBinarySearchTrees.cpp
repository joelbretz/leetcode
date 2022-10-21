class Solution {
  public:
  int numTrees(int n) {
    long catlan = 1;
    for (int i = 0; i < n; ++i) {
      catlan = catlan * 2 * (2 * i + 1) / (i + 2);
    }
    return (int) catlan;
  }
};
