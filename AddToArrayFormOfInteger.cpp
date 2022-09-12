class Solution {
  public:

  vector<int> addToArrayForm(vector<int>& nums, int k) {
    int c = 0; // carry 
    int n = nums.size(); // number of digits
    int sum = k; // current sum
    for(int i = n - 1; i >= 0; --i){
      // add current digit to current sum, update carried amount
      sum += nums[i] + c;
      c = sum / 10;
      // extract the lsb and store it.
      sum %= 10;
      nums[i] = sum;
      sum = 0;
    }
    // check if we have a carry that needs to go on the front.
    while(c){
      nums.insert(nums.begin(), c % 10);
      c /= 10;
    }
    return nums;
  }
  
  // initial intuition was to convert the vector, then add em and convert
  // back, but it doesn't work for numbers greater than INT_MAX, etc.
  vector<int> addToArrayFormRTE(vector<int>& num, int k) {

    int n = num.size();
    long long val = 0;
    for(int i = 0; i < num.size(); ++i) {
      val *= 10; val += num[i];
    }
    val += k;

    vector<int> sum;
    while(val) {
      int digit = val % 10;
      val /= 10;
      sum.push_back(digit);
    }
    reverse(sum.begin(), sum.end());
    return sum;
  }
};
