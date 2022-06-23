class Solution {
public:
  
    
    // fill the return vector from the back.
    // choose the larger square and use it, adjust pointers
    // - might be a way to save multiplication, if i save n^2
    // but that's the next version.
    vector<int> sortedSquares(vector<int>& nums) {
       vector<int> rv(nums.size());
      // two pointer approach
      int a = 0, b = nums.size() - 1; // pointer to start, end of nums
      int c = nums.size() - 1;
      int u, v; // squares
      while(a < b) {
        u = nums[a] * nums[a];
        v = nums[b] * nums[b];
        if(u > v) {
          rv[c] = u;
          --c; ++a;
        }
        else if(u == v) {
          rv[c] = u;
          --c;
          rv[c] = v;
          --c;
          ++a; --b;
        }
        else {
          rv[c] = v;
          --c;
          --b;
        }
      }
      // loop exits a == b, first element undefined/zero
      if(a==b) 
        rv[0] = nums[a] * nums[a];
      
      return rv;
    }
  
    // trival solution, runtime dependent on the sort.
    vector<int> sortedSquares2(vector<int>& nums) {
      for(auto& n : nums) {
        n = n * n;
      }
      sort(nums.begin(), nums.end());
      return nums;
    }
  
    
};
