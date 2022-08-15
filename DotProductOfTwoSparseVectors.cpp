class SparseVector {
  public:
  map<int,int> indexToValue; // index of all non zero values;
  SparseVector(vector<int> &nums) {
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] != 0)
        indexToValue[i] = nums[i];
    }
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    int product = 0;
    for(auto entry : indexToValue) {
      if(vec.indexToValue.find(entry.first) != vec.indexToValue.end())
        product += entry.second * vec.indexToValue[entry.first];
    }
    return product;
  }
};
