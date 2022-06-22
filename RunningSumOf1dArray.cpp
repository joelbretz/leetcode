class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefix_sum = 0;
        vector<int> sums;
        for(auto n : nums) { 
            prefix_sum += n;
            sums.push_back(prefix_sum);
        }
        
        return sums;
    }
};
