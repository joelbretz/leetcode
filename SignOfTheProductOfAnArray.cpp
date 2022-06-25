class Solution {
public:
    int arraySign(vector<int>& nums) {
      int pos = 0, neg = 0;
      for(auto n : nums) {
        if(n < 0) 
          ++neg;
        else if(n == 0)
          return 0;
      }
      if(neg % 2 == 0)
        return 1;
      
      return -1;
    }
};
