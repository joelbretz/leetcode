class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;

    // use iterative method of bsearch
        while(lo <= hi) {
            mid = (lo+hi) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) {
                // target goes to right of me.
                lo = mid + 1;
            }
            else {
                // target left of me.
                hi = mid - 1;
            }
        }
        return hi + 1;
    }
};
