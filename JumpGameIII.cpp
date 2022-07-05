class Solution {

  // recursive solution: 
  bool jump(vector<int>& arr, vector<bool>& visited, int pos) {

    if(pos < 0 || pos >= arr.size())
      return false;
    if(visited[pos])
      return false;

    visited[pos] = true; 
    if(arr[pos] == 0)
      return true;


    return (
      jump(arr,visited,pos + arr[pos]) || 
      jump(arr,visited,pos - arr[pos])); 

  }
  public:
  
  // recursive solution: 
  bool canReachR(vector<int>& arr, int start) {
    vector<bool> visited(arr.size(), false);
    return jump(arr,visited,start);
  }
  
  // iterative bfs style with q
  bool canReach(vector<int>& arr, int start) {
    auto n = arr.size();
    
    queue<int> q;
    q.push(start);
    vector<bool> visited(n,false);
    
    while(!q.empty()) {
      int pos = q.front();
      q.pop();
      visited[pos] = true;
      
      if(arr[pos] == 0)
        return true;
      int a = pos + arr[pos];
      int b = pos - arr[pos];
      
      if(a >= 0 && a < n && !visited[a])
        q.push(a);
      if(b >= 0 && b < n && !visited[b])
        q.push(b);
      
    }
      return false;
  }
  
};
