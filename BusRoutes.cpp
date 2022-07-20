class Solution {

  protected:
  int n;

  /// Find the intersection between two routes
  vector<int> findIntersection(vector<vector<int>>& routes, int i, int j) {
    vector<int> intersect;
    int a = 0, b = 0; 
    int stopsA = routes[i].size();
    int stopsB = routes[j].size();
    while(a < stopsA && b < stopsB) {
      if(routes[i][a] == routes[j][b]) {
        intersect.push_back(routes[i][a]);
        ++a; ++b;
      }
      else if(routes[i][a] < routes[j][b]) 
        ++a;
      else 
        ++b;
    }
    return intersect;   
  }

  // create a sets table[i][j] to true if routes i and j share any stops
  void populateIntersectionTable(vector<vector<int>>& routes, vector<vector<bool>>& table) {
    for(int i = 0; i < n - 1; ++i) {
      for(int j = i + 1; j < n; ++j) {
        auto intersect = findIntersection(routes,i,j);
        if(!intersect.empty()) {
          table[i][j] = true;
          table[j][i] = true;
        }
      }
    }
  }
  void printTable(vector<vector<bool>>& table) {
    cout << "------- table -----------" << endl;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        cout << ((table[i][j] == true) ? "1 " : "0 "); 
      }
      cout << endl;
    }
  }

  //
  void createAdjList(vector<vector<int>>& routes, vector<vector<int>>& adj) {
    // adjacent routes have intersections
    for(int i = 0; i < routes.size() - 1; ++i) {
      for(int j = i + 1; j < routes.size(); ++j) {
        auto intersect = findIntersection(routes,i,j);
        if(!intersect.empty()) {
          for(int k = 0; k < intersect.size(); ++k) {
            auto nodes = findRoute(routes, intersect[k]);
            for(auto n : nodes) {
              adj[i].push_back(n);
              adj[j].push_back(n);
            }
          }
        }
      }
    }  
  }
  void printAdjList(vector<vector<int>>& adj) {
    cout << "----------------------------------------" << endl;
    for(int i = 0; i < adj.size(); ++i) {
      cout << i << ": " ;
      for(int j = 0; j < adj[i].size(); ++j) {
        cout << adj[i][j] << " " ;
      }
      cout << endl;
    }
  }

  vector<int> findRoute(vector<vector<int>>& routes, int stop) {
    vector<int> result;
    for(int i = 0; i < routes.size(); ++i) {
      auto it = find(routes[i].begin(), routes[i].end(), stop);
      if(it != routes[i].end()) 
        result.push_back(i);
    }
    return result;
  }

  public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if(source == target)
      return 0;
    n = routes.size();

    //    vector<vector<bool>> table(n, vector<bool>(n,false));
    //    populateIntersectionTable(routes, table);
    //    printTable(table);

    vector<vector<int>> adjList(n, vector<int>());
    createAdjList(routes, adjList);
   // printAdjList(adjList);


    auto startRoute = findRoute(routes,source);
    auto endRoute = findRoute(routes,target);

    queue<int> q;
    vector<bool> seen(n, false);
    for(auto s : startRoute) {
      q.push(s);
      seen[s]  = true;
    }

    int stops = 1;
    while(!q.empty()) {
      int size = q.size();
      while(size--) {
        int rte = q.front();
        q.pop();
        if(find(endRoute.begin(), endRoute.end(), rte) != endRoute.end())
          return stops;
        for(auto a : adjList[rte]) {
          if(!seen[a]) {
            seen[a] = true;
            q.push(a);
          }
        }
      }
      ++stops;
    }
    return -1;
  }
};
