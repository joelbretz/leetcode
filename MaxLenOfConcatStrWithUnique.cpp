class Solution {
  protected:
  int dfs(vector<string>& arr, int pos, string str) {
    /// check for duplicates
    unordered_set<char> uniques(str.begin(), str.end());
    if(uniques.size() != str.size()) 
      return 0;
    
    int len = str.size();
    for(int i = pos; i < arr.size(); ++i) {
      len = max(len, dfs(arr, i + 1, str + arr[i]));
    }
    return len;
    
  }
  public:
  int maxLength(vector<string>& arr) {
    return dfs(arr, 0, ""); 
  }
}
