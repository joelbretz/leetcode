class Solution {
  public:
  bool isAlienSorted(vector<string>& words, string order) {
    // map the letters
    unordered_map<char,char> dict;
    for(int i = 0; i < 26; ++i)
      dict[order[i]] = 'a' + i;
    // replace chars in words with translation from map
    for(auto &word : words) 
      for(auto &c : word) 
        c = dict[c];
    // use is_sorted
    return is_sorted(words.begin(), words.end());
  }
};
