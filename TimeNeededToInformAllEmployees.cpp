class Solution {
  protected:
  void printReports(vector<vector<int>>& dr) {
    for(int i = 0; i < dr.size(); ++i) {
      int numReports = dr[i].size();
      if(numReports) {
        cout << i << ": " ;
        for(int j = 0; j < dr[i].size(); ++j) { 
          cout << dr[i][j] << " ";
        }
        cout << endl;
      }
    }
  }

  public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

    // generate adjacency list of direct reports
    vector<vector<int>> directReports(n,vector<int>(0));
    for(int i = 0; i < manager.size(); ++i) {
      if(i == headID)
        continue;
      //cout << i << " reports to " << manager[i] << endl;
      directReports[manager[i]].push_back(i);
    }

    // printReports(directReports);

    int time = 0;
    queue<int> q;
    q.push(headID);

    while(!q.empty()) {
      int boss = q.front();
      q.pop();
      for(int i = 0; i < directReports[boss].size(); ++i) {
        informTime[directReports[boss][i]] += informTime[boss];
        q.push(directReports[boss][i]);
      }
    }
    for(auto t : informTime) 
      time = max(time,t);
    return time;
  }
}
