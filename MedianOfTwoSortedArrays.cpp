class Solution {
  public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    //we will apply binary search on smaller array
    if(n > m) 
      return findMedianSortedArrays(nums2,nums1);

    //lower and upper limit for binary search on smaller array
    int low = 0,high = n;
    while(low <= high) {
      int cnt1 = (low + high)/2;  //count of elements we will consider on left of median from array1
      int cnt2 = (n + m)/2 - cnt1; //count of elements we will consider on left of median from array2

      // Values on left and right of median
      int leftval1 = (cnt1==0) ? INT_MIN : nums1[cnt1-1];
      int rightval1 = (cnt1==n) ? INT_MAX : nums1[cnt1];
      int leftval2 = (cnt2==0) ? INT_MIN : nums2[cnt2-1];
      int rightval2 = (cnt2==m) ? INT_MAX : nums2[cnt2];

      if(leftval1 > rightval2) 
        high=cnt1 - 1;  //if we have to take less elements from array1
      else if(leftval2>rightval1) 
        low=cnt1 + 1; //if we have to take more elements from array1

      else {
        if((n+m)%2==0) {
          return (max(leftval1,leftval2) + min(rightval1,rightval2))/2.0;
        }
        else return min(rightval1,rightval2);
      }
    }
    return 0.0;
  }
};
