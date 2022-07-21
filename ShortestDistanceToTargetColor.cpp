/*
You are given an array colors, in which there are three colors: 1, 2 and 3.

You are also given some queries. Each query consists of two integers i and c, return the shortest distance between the given index i and the target color c. If there is no solution return -1.*/
class Solution {

  void indexColors(vector<int>& colors, vector<vector<int>>& indices) {
    //vector<vector<int>> indices(3, vector<int>());
    for(int i = 0; i < colors.size(); ++i) {
      indices[colors[i]-1].push_back(i);
    }
  }
  void printIndices(vector<vector<int>>& Idx) {
    for(int i = 0; i < Idx.size(); ++i) {
      cout << i + 1 << ": ";
      for(int j = 0; j < Idx[i].size(); ++j) {
        cout << Idx[i][j] << " ";
      }
      cout << endl;
    }
  }
  
  int bsearch(vector<int>& values, int target) {
    int left = 0, right = values.size() - 1;
    int d; int smallest = INT_MAX;
    while(left <= right) {
      int mid = left + (right-left)/2;
      if(values[mid] == target)
        return 0;
      d = abs(target-values[mid]);
      if(d < smallest) {
        smallest = d;
      }
      if(values[mid] < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    return smallest;
  }
  
  public:
  vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {

    vector<vector<int>> indices(3, vector<int>());
    indexColors(colors,indices);
    //printIndices(indices);

    vector<int> result;
    for(auto q : queries) {
      int color = q[1] - 1, idx = q[0];
      if(indices[color].empty())
        result.push_back(-1);
      else
        result.push_back(bsearch(indices[color], idx));
    }
    return result; 
  }
};
