class Solution {
  public:
  // iteratively build them 
  vector<string> letterCasePermutation(string s) {
    vector<string> permutations;
    // initialize to empty
    permutations.push_back("");
    for(auto c : s) {
      int n = permutations.size();
      // loop over the current number of permutations
      // and either add a new permutation or update the current
      // ones with
      for(int i = 0; i < n; ++i) {
        if(isalpha(c)) {
          // add new permutation, update previous
          permutations.push_back(permutations[i]);
          permutations[i] += tolower(c);
          permutations[n+i] += toupper(c);
        }
        else {
          // just append the new char to known permutations
          permutations[i] += c;
        }
      }
    }
    return permutations;
  }
};
