class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort array, save size
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        
        // need 3 pointers. i,j,k for iteration
        //int i,j,k;

        // find the largest value and assume that's the closest
        // we will update closest
        int closest = nums[len - 1 ] + nums[len - 2] + nums[len - 3];

        // iterate over the vector, update closest
        for(int i = 0; i < len -2; ++i) {
            int j = i + 1; // start with j as the next element
            int k = len - 1; // and k as the last
            
            // check value, update closest and indices
            while(j < k) {
                // calculate local sum
                int sum = nums[i] + nums[j] + nums[k]; 

                // if it matches, we're done!
                if(sum == target)
                    return sum;
                
                // if not, update closest value
                if (std::abs(sum - target) < std::abs(closest - target)) {
                    closest = sum;
                }
              
                // update indices based on sum
                if(sum > target) {
                    --k;
                }
                else {
                    ++j;
                }
                    
            }

        }
        return closest;
    }
} ;
