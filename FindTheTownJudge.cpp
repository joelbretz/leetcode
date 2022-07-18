class Solution {

  public:
  int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustme(n,0);
    vector<int> ntrusted(n,0);

    for(int i = 0; i < trust.size(); ++i) {
      //ai trusts bi
      auto a = trust[i][0] - 1; auto b = trust[i][1] - 1;
      trustme[b]++;
      ntrusted[a]++;
    }
#if 0
    for(int u = 0; u < n; ++u) {
      cout << trustme[u] << " ";
    }
    cout << endl;
    for(int u = 0; u < n; ++u) {
      cout << ntrusted[u] << " ";
    }
    cout << endl;
#endif
    for(int i = 0; i < n; ++i) {
      if((trustme[i] == n-1) && (ntrusted[i] == 0))
        return i + 1; // 
    }
    return -1;

  }
};
