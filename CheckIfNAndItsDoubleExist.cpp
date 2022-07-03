class Solution {
  public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> boop;
    // check each m and see if we've already inserted 2m
    // or m / 2 of m % 2 == 0, then insert it.  "That's what", She.
    for(auto m : arr) {
      if(boop.find(2*m) != boop.end())
        return true;
      if((m % 2 == 0) && (boop.find(m/2) != boop.end()))
        return true;
      boop.insert(m);
    }
    return false;
  }
};
