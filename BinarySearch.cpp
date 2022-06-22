class Solution {
public:
    
    // recursive solution:
    int bsearch(vector<int>& nums, int lo, int hi, int target) {
        if(lo > hi)
            return -1;
        
        int mid = (lo + hi) / 2;
        if(nums[mid] == target)
             return mid;
        
        else if(nums[mid] < target) 
            return bsearch(nums,mid+1,hi,target);
        
        else
            return bsearch(nums,lo,mid-1,target);
        
    }
    
    int search(vector<int>& nums, int target) {
    
        // recursive, works. faster than only 5.39% haha
        //int p = bsearch(nums,0,nums.size()-1,target);
        //return p;
        
        int lo = 0, hi = nums.size() - 1, mid;
        while(lo <= hi) {
            mid = (lo + hi) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                lo = mid + 1;
            else 
                hi = mid - 1;
        }
        return -1;
    }
};
