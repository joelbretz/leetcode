class Solution {
  
  void printHash(unordered_map<char,int>& H) {
    for(auto elem : H) 
      cout << "[" << elem.first << "," << elem.second << "]" << endl;
  }
  public:
  vector<int> findAnagrams(string s, string p) {
    unordered_map<char,int> pHash;
    unordered_map<char,int> sHash;
    
    vector<int> indices; 
    // create the hash for p
    for(auto c : p) 
      pHash[c]++;

    int left = 0, right = p.length() - 1;
    // create the initial hash for the window
    for(int i = 0; i < p.length() ; ++i)
      sHash[s[i]] += 1;
    
    
    // move our window through s
    do {
      
      if(sHash == pHash)
        indices.push_back(left);
      
      // remove the letter on front of the window, increment l
      sHash[s[left]] -= 1;
      if(sHash[s[left]] == 0)
        sHash.erase(s[left]);
      left++;
      // add the next letter, increment r
      right++;
      sHash[s[right]] += 1;
    } while(right < s.length()); 
    
    return indices;
  } 
};
