class Solution {
  public:
  // Add and carry as needed: back to front. elementary 
  // school style addition
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    // loop from the back
    for(int i = n - 1; i >= 0; --i) {
      if(digits[i] == 9)
        digits[i] = 0;
      else {
        digits[i] += 1;
        return digits;
      }
    }
    // special case, all nines
    auto it = digits.begin(); 
    digits.insert(it,1);
    return digits;
  }
};
