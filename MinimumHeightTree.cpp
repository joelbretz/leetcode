class Solution {
  
  void printAdj(map<int,set<int>>& adj) {
    auto it = adj.begin();
    for(; it != adj.end(); ++it) {
      cout << it->first << ": " ;
      for(auto jt = it->second.begin(); jt != it->second.end(); ++jt) {
        cout << *jt << " ";
      }
      cout << endl;
    }
  }
  public: 
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<int> mhtroots; 
    // check whether we actually have to calculate the solution.
    if(n < 3) {
      for(int i = 0; i < n; ++i)
        mhtroots.push_back(i);
      return mhtroots;
    } 

    // create adjacency list, use map of sets because
    // we will be removing nodes later as we reduce the graph
    map<int,set<int>> adj;
    for(auto e : edges) {
      adj[e[0]].insert(e[1]);
      adj[e[1]].insert(e[0]);
    }
    //printAdj(adj);
    
    // create a list of leaf nodes
    queue<int> leaves;
    for(int i = 0; i < adj.size(); ++i) {
      if(adj[i].size() == 1)
        leaves.push(i);
    }
    
    // reduce tree as far as possible by removing 
    // edges to leaf nodes
    int size = n;
    while(size > 2) {
      size -= leaves.size();
      queue<int> abandoned; // nodes that become leafs this iteraton
      
      while(leaves.size()) {
        // determine neighbor
        auto leaf = leaves.front();  // get leaf 
        leaves.pop(); 
        auto neighbors = adj[leaf];  // get neighbor set
        auto next = *neighbors.begin(); // get neighbor
        //cout << " pruning " << leaf << " from " << next << endl;
        // remove leaf from adjSet
        adj[next].erase(leaf);

        // check if it's leaf and add it
        if(adj[next].size() == 1) {
          //cout << " adding " << next << " to leaves " << endl;
          abandoned.push(next);
        }
      }
      leaves = abandoned;
    }
    while(!leaves.empty()) {
      mhtroots.push_back(leaves.front());
      leaves.pop();
    }
    return mhtroots;  
  }
};

class Solution2TLE {
  protected:
  bool compare(pair<int,int>& a, pair<int,int>& b) {
    if(a.first >= b.first)
      return true;
    return false;
  }

  void printAdj(vector<vector<int>>& adj) {
    for(int i = 0; i < adj.size(); ++i) {
      cout << i << ": " ;
      for(int j = 0; j < adj[i].size(); ++j) {
        cout << adj[i][j] << " ";
      }
      cout << endl;
    }
  }

  public:
  // intuition: MHT is the tree rooted by the node with the most edges
  // the works, but you get TLE on the 5000 node tedt case
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

    vector<int> mhtroots; 
    // check whether we actually have to calculate the solution.
    if(n < 3) {
      for(int i = 0; i < n; ++i)
        mhtroots.push_back(i);
      return mhtroots;
    } 

    // create adjacency list
    vector<vector<int>> adj(n, vector<int>());
    for(auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    printAdj(adj);

    // put non leaf nodes into a pq 
    priority_queue<pair<int,int>> pq; // num edges, node num 
    for(int i = 0; i < adj.size(); ++i) {
      int sz = adj[i].size();
      if(sz > 1)
        pq.push({sz,i});
    }

    // determine the heights of the tree with roots in pq order
    // use bfs, just because i want to.
    map<int,vector<int>> heightMap;

    //cout << "pq size =  " << pq.size() << endl;
    while(!pq.empty()) {
      vector<bool> visited(n, false);
      queue<int> q;
      auto pqnode = pq.top();
      pq.pop();
      //cout << "examine node " << pqnode.second << ", with " << pqnode.first << " connections" << endl;

      q.push(pqnode.second);
      int height = -1;
      while(!q.empty()) {
        ++height;
        int size = q.size();
        while(size--) {
          auto node = q.front();
          q.pop();
          for(int i = 0; i < adj[node].size(); ++i) {
            if(!visited[adj[node][i]]) {
              visited[adj[node][i]] = true;
              q.push(adj[node][i]);
            }
          }
        }
      }
      //cout << "  height of tree rooted at " << pqnode.second << " = " << height << endl;
      heightMap[height].push_back(pqnode.second);

    }
    for(auto entry : heightMap) {
      //cout << "h = " << entry.first << ": " ;
      for(auto n : entry.second) { 
        //cout << n << " ";
        mhtroots.push_back(n);
      }
      //cout << endl;
      break;
    }
    return mhtroots;
  }
};
