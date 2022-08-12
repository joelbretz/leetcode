class Solution {
  public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> kClosest;
 
    int lo = 0, hi = arr.size() -1 ;
    while(hi - lo >= k){
      if(abs(arr[lo] - x) > abs(arr[hi] - x))
        lo++;
      else
        hi--;
    }

    for(int i = lo; i <= hi; i++){
      kClosest.push_back(arr[i]);
    }
    return kClosest;
  }
};
