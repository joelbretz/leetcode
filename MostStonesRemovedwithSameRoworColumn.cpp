/**
The system stones on the 2D plane can be visualized as a graph having stones as the vertices and every 2 stones which have common x coordinate or y coordinate will have an egde between them.
After connecting all the stones accordingly (as mentioned above) you have to find the total number of connected components.
Now is the tricky part, For each components having s number of stones as vertices you can remove s-1 stones from that component. Just take some time and think about it , you will understand.
Since each component is made us of stones which are sharing coordinates and it is given in the ques that we have to remove the stones which share coordinates there fore we have to remove stones from the components considering one component at a time.
Now after removing the stones each component will left with only one stone so we have to calculate the total number of components which will be equal to the total number of stones left after the removal.
***/


class Solution {
  protected:
  int nStones;
  int x_max;
  int y_max;

  void createAdjList(vector<vector<int>>& stones, vector<vector<int>>& adjList, 
                     map<int,vector<int>>& x_map, map<int,vector<int>>& y_map) {
    for(int i = 0; i < nStones; ++i) {
      int x = stones[i][0], y = stones[i][1];
      for(auto samex : x_map[x]) {
        if(i == samex)
          continue;
        adjList[i].push_back(samex);
      }
      for(auto samey : y_map[y]) {
        if(i == samey)
          continue;
        adjList[i].push_back(samey);
      }
    }

  }
  void printAdj(vector<vector<int>>& adj) {
    for(int i = 0; i < nStones; ++i) {
      cout << i << ": " ;
      for(int j = 0; j < adj[i].size(); ++j) {
        cout << adj[i][j] << " " ;
      }
      cout << endl;
    }
  }

  ///======================================================
  void createTable(vector<vector<int>>& nodes, vector<vector<int>>& table) {
    for(int i = 0; i < nodes.size(); ++i) {
      int x = nodes[i][0], y = nodes[i][1];
      x_max = max(x_max, x + 1); 
      y_max = max(y_max, y + 1); 
      table[x][y] = i;
    }
  }
  void printTable(vector<vector<int>>& T) {
    for(int x = 0; x < x_max; ++x) {
      for(int y = 0; y < y_max; ++y) {
        cout << T[x][y] << " ";
      }
      cout << endl;
    }
  }
  ///======================================================
  void createMaps(vector<vector<int>>& stones, map<int,vector<int>>& x_map, map<int,vector<int>>& y_map) {
    for(int i = 0; i < nStones; ++i) {
      int x = stones[i][0];
      int y = stones[i][1];
      x_map[x].push_back(i);
      y_map[y].push_back(i);
    }
  }
  void printMap(map<int,vector<int>>& M, char c) {
    for(auto neighborList : M ) {
      int x = neighborList.first;
      cout << c << " = " << x << ": ";
      for(auto n : neighborList.second) {
        cout << n << " ";
      }
      cout << endl;
    }
  }
  ///======================================================

  void dfs(vector<vector<int>>& adjList, vector<bool>& visited, int nodeNo, int& size) {
    
    visited[nodeNo] = true;
    size += 1;
    // loop over neighbors call dfs on them
    for(int i = 0; i < adjList[nodeNo].size(); ++i) {
      if(!visited[adjList[nodeNo][i]]) {
        dfs(adjList, visited, adjList[nodeNo][i], size);
      }
    }
  }

  public:
  int removeStones(vector<vector<int>>& stones) {
    nStones = stones.size();
    
    map<int,vector<int>> x_map; // x value, stones with that value
    map<int,vector<int>> y_map; // y value, stones with that value
    createMaps(stones,x_map,y_map);
    
    vector<vector<int>> adjList(nStones, vector<int>());
    createAdjList(stones, adjList, x_map, y_map);

    vector<bool> visited(nStones, false);
    // find connected componenents
    int components = 0, removed = 0;
    for(int i = 0; i < nStones; ++i) {
      if(!visited[i]) {
        int componentSize = 0;
        components++;
        dfs(adjList, visited, i, componentSize);
        removed += componentSize - 1;
      }
    }
    return removed;
  }
};
