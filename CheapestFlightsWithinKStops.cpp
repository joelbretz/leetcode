class Solution
{
  public:
  int findCheapestPrice(int n, vector<vector <int>>& flights, int src, int dst, int k)
  {
    // Run Bellman-Ford and relax only k edges
    vector<int> costs(n, INT_MAX);
    vector<int> temp(n, INT_MAX);
    costs[src] = 0;
    temp[src] = 0;

    for (int i = 0; i <= k; i++) { // number of edges to relax
      // iterate over all edges
      //cout << "iteration " << i << endl;
      for (auto edge: flights) {
        int src = edge[0], dest = edge[1], cost = edge[2];
        //cout << "  src = " << src << ", dest = " << dest << ", cost = " << cost << endl;
        // check the distance and update costs
        if (temp[src] != INT_MAX) {
          costs[dest] = min(costs[dest], temp[src] + cost);
          //cout << "   updated costs[" << dest << "] = " << costs[dest] << endl;
        }
      }
      // reset temp array every iteration
      temp = costs;
    }
    // check if we got there.
    if (costs[dst] == INT_MAX)
      return -1;
    return costs[dst];
  }
};
