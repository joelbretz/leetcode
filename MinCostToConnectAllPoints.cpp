class Solution {
  protected:
  int manhattan(vector<int>& p1, vector<int>& p2) {
    int d = abs(p2[1] - p1[1]) + abs(p2[0] - p1[0]);
    return d;
  }
  void printTable(vector<vector<int>>& table) {
    for(int i = 0; i < table.size(); ++i) {
      for(int j = 0; j < table[i].size(); ++j) {
        cout << table[i][j] << " ";
      }
      cout << endl;
    }
  }

  public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int numPoints = points.size();
    int total = 0;
    int edges = 0;
    
    vector<bool> used(numPoints, false); // visited && added
    vector<int> least(numPoints, INT_MAX);   // smallest d to next point
    least[0] = 0; 
    
    while(edges < numPoints) {
      pair<int,int> minEdge {INT_MAX, -1}; //edge cost, node
      
      // find least cost edge
      for(int p = 0; p < numPoints; ++p) {
        if(least[p] < minEdge.first && !used[p]) {
          minEdge = { least[p], p};
        }
      }
      // add it to the solution
      total += minEdge.first;
      edges++;
      used[minEdge.second] = true;
      // find distances from current point to next point
      for(int nextp = 0; nextp < numPoints; ++nextp) {
        int d = manhattan(points[minEdge.second], points[nextp]);
        if(d < least[nextp] && !used[nextp])
          least[nextp] = d;
      }
      
    }
    return total;
  }
  
  // Brute Force-ish solution. works for examples but fails
  // one of the submit testcases.  leaving it here for reference
  int minCostConnectPointsBF(vector<vector<int>>& points) {

    // hint says to connect all pairs with a weighted edge.
    // so right here, we're O(n_squared) if im doing that, then i should 
    // just pick a point and take the smallest edge after.
    int numPoints = points.size();
    int total = 0;    // cost of edges taken (return value)

    // determine distance between all nodes. save as a table of costs
    vector<vector<int>> distance(numPoints, vector<int>(numPoints, 0));
    for(int i = 0; i < numPoints - 1; ++i) {
      for(int j = i + 1; j < numPoints; ++j) {
        int d = manhattan(points[i], points[j]);
        distance[i][j] = d;
        distance[j][i] = d;
      }
    }
    printTable(distance);

    vector<bool> visited(numPoints, false);
    visited[0] = true; 

    int currNode = 0; 
    int numEdges = 1; // number of edges taken 
    while(numEdges < numPoints - 1) {
      // determine the lowest cost edge from this node    
      pair<int,int> minEdge {INT_MAX, -1}; //edge cost, node
      cout << "currNode: " << currNode << ", total = " << total << endl;
      for(int j = 0; j < numPoints; ++j) {
        if(j == currNode)
          continue;
        if(distance[currNode][j] < minEdge.first && !visited[j]) {
          cout << "  updating minEdge for " << currNode << ". using node " << j << ", dist = " << 
            distance[currNode][j] << endl;
          minEdge = { distance[currNode][j], j }; 
        }
      }
      cout << "marking " << minEdge.second << " visited." << endl;
      visited[minEdge.second] = true;
      total += minEdge.first;
      currNode = minEdge.second;
      numEdges++;
      cout << "   total = " << total << ", numEdges = " << numEdges << endl;
    }
    // connect last poimt
    for(int i = 0; i < numPoints; ++i) {
      if(visited[i])
        continue;
      else {
        // add the
        pair<int,int> minEdge {INT_MAX, -1}; //edge cost, node
        cout << "currNode: " << i << ", total = " << total << endl;
        for(int j = 0; j < numPoints; ++j) {
          if(j == i)
            continue;
          if(distance[i][j] < minEdge.first) {
            cout << "  updating minEdge for " << i << ". using node " << j << ", dist = " << 
              distance[i][j] << endl;
            minEdge = { distance[i][j], j }; 
          }
        }
        total += minEdge.first;
      }
    }

    return total;
  }
};
