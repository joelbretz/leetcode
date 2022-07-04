class Solution {

  void printAdjList(vector<vector<pair<int,int>>>& adj) {
    cout << "-----------------------------" << endl;
    for(int i = 0; i < adj.size(); ++i) {
      cout << i << ": " ;
      for(int j = 0; j < adj[0].size(); ++j) {
        cout << adj[i][j].first << "," << adj[i][j].second << " ";
      }
      cout << endl;
    }
  }

  // our adjacency list will have the number of the
  // next node and the color of the edge to it
  const int red = 0;
  const int blue = 1;
  public:

  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {

    // Build adjacency list
    // 0 -> {nodeNo,color} , {nodeNo,color} ...
    vector<vector<pair<int,int>>> adj(n);
    // add red edges: 
    for(auto edge : redEdges)   
      adj[edge[0]].push_back({edge[1], red});
    // add blue edges
    for(auto edge : blueEdges) 
      adj[edge[0]].push_back({edge[1], blue});
   // printAdjList(adj);

    vector<int> dist(n,-1); //< distance to node. 
    dist[0] = 0;  // mark start having a distance of zero

    vector<bool> redVisited(n,false); 
    vector<bool> blueVisited(n,false); 

    queue<pair<int,int>> q; //< queue for bfs {next_node, edge_color}
    q.push({0,-1}); // push node zero

    int depth = -1; //< distance from node 0
    redVisited[0] = true;
    blueVisited[0] = true;

    // initiate the bfs:
    while(!q.empty()) {
      ++depth;
      int size = q.size();
      
      while(size--) {
        // get next element from queue
        auto elem = q.front();
        q.pop();
        // save the node number and color for readability
        int nodeNo = elem.first;  
        int type = elem.second;

        // if there's no depth for this node, mark it.
        if(dist[nodeNo] == -1) 
          dist[nodeNo] = depth;
        
        // push neighbors which have a differnt color path and we haven't visited
        for(auto edge : adj[nodeNo]) {
          int nextNode = edge.first;
          int nextType = edge.second;
          if((type == blue || type == -1) && nextType == red) {
            if(!redVisited[nextNode]) {
              redVisited[nextNode] = true;
              q.push({nextNode,red});
            }
          }
          if ((type == red || type == -1) && nextType == blue) {
            if(!blueVisited[nextNode]) {
              blueVisited[nextNode] = true;
              q.push({nextNode,blue});
            }
          }
        }
      }
    }
    return dist;
  }

};
