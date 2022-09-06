class Solution {
  protected:
  static int count1Bits(int x) {
    int count = 0;
    while (x != 0) {
      x = x & (x - 1);
      count++;
    }
    return count;
  }
  
  static bool comp(const int &a, const int &b) {
    const auto aBits = count1Bits(a);
    const auto bBits = count1Bits(b);
    if (aBits == bBits)
      return a < b;
    return aBits < bBits;
  }
  
  public:
  vector<int> sortByBits(vector<int>& arr) {
    std::sort(arr.begin(), arr.end(), comp);
    return arr;
    }
};
