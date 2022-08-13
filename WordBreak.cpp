class Solution {
  public:
  bool wordBreak(string s, vector<string>& wordDict) {
    // use a set so we can do lookups as we parse s
    set<string> wordSet(wordDict.begin(), wordDict.end());
    queue<int> q; // the queue for our bfs
    vector<bool> visited(s.length(), false);
    
    q.push(0); // start index
    while(!q.empty()) {
      int front = q.front();
      q.pop();
      if(visited[front])
        continue;
      
      //check if any of the patterns exist in the dict
      // le (false) lee (false) leet (true)
      // mark position as place to examine during bfs
      for(int back = front + 1; back <= s.length(); ++back) {
        if(wordSet.find(s.substr(front, back - front)) != wordSet.end()) {
          q.push(back);
          if(back == s.length())
            return true;
        }
      }
      visited[front] = true;
    }
    return false;
  }
};
