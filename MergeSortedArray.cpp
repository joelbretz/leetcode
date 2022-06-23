class Solution {
  public:
  // simple version.
  void merge_simple(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // ok so just using STL..
    // copy nums2 into nums1.

    int i = m, j = 0;
    for(;i < m + n; ++i,++j) {
      nums1[i] = nums2[j];
    }
    // then sort that shit.
    sort(nums1.begin(), nums1.end());
    // doneski
    return;
  }
  // another, faster way 
  // compare from the right and work back.
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // point to the end of the arrays
    int p1 = m - 1, p2 = n - 1;
    // move backwards
    for(int p = m + n - 1; p >= 0; --p) {
      if(p2 < 0)
        break;
      if(p1 >= 0 && nums1[p1] > nums2[p2]) {
        nums1[p] = nums1[p1];
        p1 -= 1;
      }
      else {
        nums1[p] = nums2[p2];
        p2 -= 1;
      }
    }
  }
};
