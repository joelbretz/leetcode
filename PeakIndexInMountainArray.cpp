class Solution {
  public:
  
  // bsearch for it, checking nums[mid] < nums[mid + 1]
  int peakIndexInMountainArray(vector<int>& arr) {
    int lo = 0, hi = arr.size() - 1, mid;
    
    while(lo < hi) {
      mid = (lo + hi) / 2;
      if(arr[mid] < arr[mid+1])
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }
  
  // straightforward O(n) solution:
  int peakIndexInMountainArray2(vector<int>& arr) {
    int curr = arr[1];
    for(int i = 2; i < arr.size(); ++i) {
      if(arr[i] < curr)
        return (i-1);
      curr = arr[i];
    }
  return -1;
  }
};
