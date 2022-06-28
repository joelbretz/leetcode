  public:
  // 1st thought: add the sum of each sliding window of odd length to 
  // a prefix_sum using std::accumulate
  int sumOddLengthSubarrays(vector<int>& arr) {
    // n = 1;
    int sum = accumulate(arr.begin(), arr.end(),0);
    // window indexes
    int left, right;
    
    for(int i = 3; i <= arr.size(); i += 2 ) {
      // i = window size.
      left = 0; right = i - 1;
      while(right < arr.size()) {
        auto v = accumulate(arr.begin() + left, arr.begin() + left + i, 0);
        sum += v; 
        ++left; ++right;
      }
    }
    return sum;
  }
};
