class Solution {
  public:
  vector<int> findOriginalArray(vector<int>& changed) {
    
    // store size and check it to save calculations.
    int nLeft = changed.size(); 
    if(nLeft & 0x1)
      return {};
    // build frequency count of each value
    map<int,int> valueCount;
    for(auto v : changed) 
      valueCount[v]++;
    
    vector<int> original;
    for(auto& elem : valueCount) { 
      while(elem.second > 0) {
        original.push_back(elem.first);
        elem.second--;
        valueCount[elem.first * 2]--;
        nLeft -= 2;
      }
    }
    if(nLeft)
      return {};
    
    return original;
  }
};
