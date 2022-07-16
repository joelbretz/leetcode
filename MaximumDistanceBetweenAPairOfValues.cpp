class Solution {
  public:
  
  inline int distance(int i, int j) { return j - i;}
  
  bool isValid(int i, int j, vector<int>& v1, vector<int>& v2) {
    if((i <= j) && (v1[i] <= v2[j]))
      return true;
    return false;
  }
  
  int farthestValueSmaller(vector<int>& nums,int start, int target) {     
    int left = start, right = nums.size()-1;
    int mid = 0, farthest = 0;
    // find the index of the first number smaller than target
    while(left <= right) {
      mid = left + (right - left)/2;
      if(mid >= start && target <= nums[mid]) {
        farthest = max(farthest, mid - start);
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    return farthest ;
  }
  
  // both arrays are sorted in a non-increasing way this means that 
  // for each value in the first array. 
  //     We can find the farthest value smaller than it using binary search.
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    
    cout << "==================================" << endl;
    int maxDist = 0 ;
    for(int i = nums1.size() - 1; i >=0; --i) {
      int j = farthestValueSmaller(nums2,i, nums1[i]);
      maxDist = max(maxDist, j); 
    }
    return maxDist;
    
  }
