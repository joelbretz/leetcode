class Solution {
public:
     // 0 index, nums1 is a subset of num2
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // for each i in nums1, find j in nums2 such that nums1[i] = nums2[j]
      unordered_map<int,int> valueToIndex;
      for(int i = 0; i < nums2.size(); ++i) {
        valueToIndex[nums2[i]] = i; 
      }
      vector<int> nextGreater(nums1.size(), -1);
      for(int i = 0; i < nums1.size(); ++i) {
        //cout << "nums1["<< i <<"] = " << nums1[i] ;
        int j = valueToIndex[nums1[i]] + 1;
        //cout << ", nums2[" << j - 1 <<"] = " << nums2[j-1] << endl;
        for(; j < nums2.size(); ++j) {
          //cout <<"\tnums2[" << j << "] = " << nums2[j] << " ";
          if(nums2[j] > nums1[i]) {           
            nextGreater[i] = nums2[j];
            break;
          }
          //cout << endl;
        }
      }
      return nextGreater;
      
    }
  
};
