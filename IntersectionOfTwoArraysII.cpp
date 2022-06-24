class Solution {
  public:
  
  // create a hash map of number,count in the smaller array,
  // then check the overlap manually
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
    // exchange order if needed
    if(nums1.size() > nums2.size()) 
      return intersect(nums2,nums1);
    
    // hash the smaller one
    unordered_map<int,int> count;
    for(auto n : nums1 ) 
      count[n]++;
    
    
    int k = 0; // insertion pointer
    // check stuff in nums2 to see if it exists in the hash/count of nums1
    for(auto n : nums2) {
      auto it = count.find(n);
      if(it != count.end()) { // found
        // check that num remaining isnt zero
        if(it->second > 0) {
           --it->second;
           nums1[k++] = n;
        }
      }
    }
    return vector(nums1.begin(), nums1.begin() + k);
  }
  
  // obv approach, use STL set intersection (which is oddly on vector and not std::set)
  vector<int> intersect_stl(vector<int>& nums1, vector<int>& nums2) {
    // set_intersection requires sorted vectors
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // use stl::erase with set_intersection to copy the result
    // into set1, then erase the rest to the right.
    nums1.erase(
      set_intersection(begin(nums1), end(nums1),
                       begin(nums2), end(nums2), 
                                                 begin(nums1)), end(nums1));
    return nums1;
  }
};
