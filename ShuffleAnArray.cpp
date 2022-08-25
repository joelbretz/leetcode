class Solution {
  protected:
  vector<int> original;
  vector<int> shuffled;
  unsigned int seed;
  public:
  
  Solution(vector<int>& nums) : original(nums.begin(), nums.end()) , 
    shuffled(nums.begin(), nums.end()), seed(time(0)) {
      srand(seed);
  }

  vector<int> reset() {
    shuffled  = original;
    return original;
  }

  vector<int> shuffle() {
    for(int i = 0; i < shuffled.size(); ++i) {
      swap(shuffled[i], shuffled[rand() % shuffled.size()]);
    }
    return shuffled;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
