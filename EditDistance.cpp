class Solution {
  // This problem asks for the Levenshtein distance

  public:
  int minDistance(string word1, string word2) {
    int l1 = word1.length(), l2 = word2.length();
    if(l1 == 0)
      return l2;
    if(l2 == 0)
      return l1;
    
    // distance table
    vector<vector<int>> dist(l1 + 1, vector<int>(l2 + 1, 0));
    // populate 1st row and column:
    for(int r = 0; r <= l1; ++r)
      dist[r][0] = r;
    for(int c = 0; c <= l2; ++c)
      dist[0][c] = c;
    
    for(int r = 1; r <= l1; ++r) {
      for(int c = 1; c <= l2; ++c) {
        //compare current letters 
        int cost;
        if(word1[r-1] == word2[c-1])
          cost = 0;
        else
          cost = 1;
        // update distance (r,c) with min of surrounding values
        dist[r][c] = min(min(dist[r-1][c] + 1, dist[r][c-1]+1),dist[r-1][c-1] + cost);
      }
    }
    return dist[l1][l2];
  }
};
