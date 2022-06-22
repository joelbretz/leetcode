class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix_sum = 0;
        // Precompute prefix sums 
        // P[i] = nums[0] + nums[1] + ... nums[i-1]
        vector<int> sums;
        for(auto n : nums) {
            sums.push_back(prefix_sum);
            prefix_sum += n;
        }
        sums.push_back(prefix_sum);

        // left = P[i]
        // right = P[P.size - 1] - P[i] - nums[i]
        int left, right ;
        for(int i = 0; i < sums.size() - 1; ++i) {
            left = sums[i];
            right = sums[sums.size() - 1] - sums[i] - nums[i];
            if(left == right)
                return i;
        }
        return -1;
    }
};
