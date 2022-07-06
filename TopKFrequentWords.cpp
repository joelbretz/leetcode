class Solution {

  static bool by_descending_value(pair<string,int>& a, pair<string,int>& b) {
    if(a.second > b.second)
      return true;
    else if (a.second == b.second) 
      return a.first <  b.first;

    return false;
  }
  public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    map<string,int> wordCount;
    // count em
    for(auto w : words) 
      wordCount[w]++;

    vector<pair<string,int>> v (wordCount.begin(), wordCount.end());
    sort(v.begin(), v.end(), by_descending_value);

    vector<string> output;
    for(int i = 0; i < k; ++i)
      output.push_back(v[i].first);

    return output;
  }
};
