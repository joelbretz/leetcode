class Solution {
  protected:
  int numNodes;
  
  public:
  int shortestPathLength(vector<vector<int>>& graph) {
    numNodes = graph.size();
    if(numNodes == 1)
      return 0;
    
    unsigned int endingMask = (1 << numNodes) - 1;
    vector<vector<bool>> seen(numNodes, vector<bool>(endingMask, false));
    
    //cout << "----------------------------------" << endl;
    //cout << "nodes: " << numNodes << ", endMask: " << std::bitset<8>(endingMask) << endl;
    queue<pair<int,int>> q; 
    // add all nodes to the queue
    for(int i = 0; i < numNodes; ++i) {
      //cout << "adding { " << i <<"," << std::bitset<8> (1<<i) <<"}" << endl;
      q.push({i, 1 << i});
      seen[i][1 << i] = true;
    }
    
    int steps = 0;
    while(!q.empty()) {
      int size = q.size();
      while(size--) {
        auto node = q.front().first;
        auto mask = q.front().second;
        q.pop();
        
        // loop over my neighbors
        for(int neighbor : graph[node]) {
          int nextMask = mask | (1 << neighbor);
          if(nextMask == endingMask) 
            return (steps + 1);
          if(!seen[neighbor][nextMask]) {
            seen[neighbor][nextMask] = true;
            q.push({neighbor, nextMask});
          }
        }
      }
      steps += 1;
    }
    return -1;
  }
};
