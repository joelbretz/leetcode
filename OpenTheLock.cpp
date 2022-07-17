class Solution {
  protected:

  public:
  int openLock(vector<string>& deadends, string target) {

    string curr = "0000";
    // check that were not starting in a deadend state.
    if(find(deadends.begin(), deadends.end(), curr) != deadends.end())
      return -1;
    
    // create a set to prevent re-visiting states
    unordered_set<string> seen;
    for(auto d : deadends) 
      seen.insert(d);
    
    // use a queue for a bfs
    queue<string> q;
    // push init value (0000) on both
    q.push(curr);
    seen.insert(curr);

    //cout << "=============================" << endl;
    int turns = -1;
    while(!q.empty()) {
      turns += 1;
      int size = q.size();
      while(size--){
        curr = q.front();
        q.pop();
        // check combo
        if(curr == target)
          return turns;

        // add valid turns to the queue 
        for(int i = 0; i < 4; ++i) {
          string rollUp = curr;
          string rollDown = curr;

          if(curr[i] == '0') {
            rollUp[i] = '1';
            rollDown[i] = '9';
          }
          else if(curr[i] == '9') {
            rollUp[i] = '0';
            rollDown[i] = '8';
          }
          else {
            rollUp[i] = curr[i] + 1;
            rollDown[i] = curr[i] - 1;
          }
          
          // check if it's a deadend or if we've already seen it.
          if(seen.find(rollUp) == seen.end()) {
            //cout << " adding " << rollUp << endl;
            q.push(rollUp);
            seen.insert(rollUp);
          }
          if(seen.find(rollDown) == seen.end() ) {
            //cout << " adding " << rollDown << endl;
            q.push(rollDown);
            seen.insert(rollDown);
          }
        }
      }
    }
    return -1;
  }
};
