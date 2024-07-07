class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // gotta sort the array to solve this problem & grab the length/size
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> result;
        // verify length
        if (len < 4)
            return result;

        for (int i = 0; i < len - 3; ++i) {
            for (int j = i + 1; j < len - 2; ++j) {
                int k = j + 1; 
                int l = len - 1;
    
                while (k < l) {

                    int sum = nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum == target) {
                        // save this foursome
                        vector<int> v({nums[i], nums[j], nums[k], nums[l]});
                        result.push_back(v);

                        // check for duplicates, move indices as needed
                        while (nums[k] == nums[k + 1])
                            ++k;
                        while (nums[l] == nums[l - 1])
                            --l;

                        ++k;
                        --l;
                    } else if (sum < target) {
                        ++k;
                    } else {
                        --l;
                    }
                } // end while( k < l )
                // check for duplicates on j
                while (nums[j] == nums[j + 1])
                    ++j;
            } // end for loop on j
            // check for dupes on i
            while (nums[i] == nums[i + 1])
                ++i;
        } // end for loop in i
        return result;
    } // end fourSum
};
