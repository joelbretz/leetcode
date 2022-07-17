class Solution {
  
  string allowed = "ACGT";
  
  public:
  int minMutation(string start, string end, vector<string>& bank) {
    // check base cases: a.)start=end, b.)empty bank, c.)end not in bank.
    if (start == end)
       return 0;
    else if(bank.empty())
      return -1;
    else if(find(bank.begin(), bank.end(), end) == bank.end())
      return -1;
    
    int changes = 0;
    // keep track of strings we've already checked. 
    unordered_set<string> seen; 
    // queue for use with bfs
    queue<string> q;
    seen.insert(start);
    q.push(start) ;
    
    while(!q.empty()) {
      int size = q.size();
      changes += 1;
      while(size--) {
        auto curr = q.front();
        q.pop();
        for(int i = 0; i < curr.length(); ++i) {
          char tmp = curr[i];
          for(int j = 0; j < 4; ++j) {
            // no change
            if(curr[i] == allowed[j])
              continue;
            
            // replace the current charactor
            curr[i] = allowed[j];
            
            // check new string for = end or if we've already seen it
            if(curr == end) { 
              return changes;
            }
            else if(seen.find(curr) != seen.end()) { 
              continue;
            }
            else {
              seen.insert(curr);
            }
            
            // check and see if this permutation is in the bank.
            auto it = find(bank.begin(), bank.end(), curr);
            if( it != bank.end() ) { 
              q.push(curr);
            }
          }
          curr[i] = tmp;
        }
      }
    }
    return -1;
  }
};
