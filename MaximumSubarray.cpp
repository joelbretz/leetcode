class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int sum = nums[0];
        for(int i  = 1; i < nums.size(); ++i) {
            auto n = nums[i];
            curr = max(n, curr + n) ;
            sum = max(sum,curr);
        }
        return sum;
    }
};

