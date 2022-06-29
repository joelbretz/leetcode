class Solution {
  void printArr(vector<int>& A) {
    cout << "[";
    for(auto a : A)
      cout << a << " ";
    cout << "]" << endl;
  }
  
  public:
  // Use bsearch:
  //[2, 3, 4, 7, 11]  input 
  //[1, 2, 3, 4, 5]   if none were missing
  //[1, 1, 1, 3, 6 ]  missing integers
  int findKthPositive(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1;
    
    int mid, missing;
    while(left <= right) {
      mid = (left + right) / 2; // left + (right - left) / 2
      
      // determine missing at this index:
      missing = arr[mid] - mid - 1;
      //cout << "i:" << mid << ", arr[i]=" << arr[mid] << ", missing=" << missing << endl;
      // move right
      if(missing < k)
        left = mid + 1;
      else
        right = mid - 1;
    }
    // this exits with kth missing after left
    return left + k;
  }
  
  // Is there a divide and conquer solution?
  // there would still be n comparisons though.
  
  // Single pass, O(n) solution: (Brute Force)
  int findKthPositiveBF(vector<int>& arr, int k) {
    if (k <= arr[0] - 1) 
      return k;

    int a = 0, b = 1; ///< indices
    int diff;

    k -= (arr[0] - 1);
    //cout << " k:" << k << endl;
    for(;b < arr.size(); ++a, ++b) {
      diff = arr[b] - arr[a] - 1;
      if(k <= diff) {
        return(arr[a] + k);
        }
      k -= diff;
      //cout << "a: " << a << ", b:" << b << ", k:" << k << endl;
    }
    return arr[a] + k;
  }
};
