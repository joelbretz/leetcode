class Solution {
  protected:
  
  void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int currRoom) {
    
    if(visited[currRoom])
      return;
    visited[currRoom] = true;
    
    for(auto key : rooms[currRoom]) {
      dfs(rooms,visited,key);
    }
  }
  
  public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int numRooms = rooms.size(); 
    vector<bool> visited(numRooms,false);
    
    dfs(rooms,visited,0);
    for(auto v : visited) {
      if(!v)
        return false;
    }
    return true;
  }
};
