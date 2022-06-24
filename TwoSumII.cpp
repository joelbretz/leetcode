class Solution {
  public:
  // 1-indexed, sorted
  vector<int> twoSum(vector<int>& numbers, int target) {
    int a = 0, b = numbers.size() - 1;
    vector<int> rv;  
    while( a < b ) {
      auto sum = numbers[a] + numbers[b];
      if(sum == target) {
        rv.push_back(a+1);
        rv.push_back(b+1);
        return rv;
      }
      else if(sum < target) {
        ++a;
      }
      else {
        --b;
      }
    }
    return rv;
  }
};
