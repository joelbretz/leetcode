class Solution {
  public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    if(arr.size() < 3)
      return true;

    int slope = arr[1] - arr[0];
    for(int i = 1; i < arr.size() - 1; ++i) {
      int s = arr[i+1] - arr[i];
      if(s != slope)
        return false;
    }
    return true;
  }
};
