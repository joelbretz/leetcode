class Solution {
  public:
  // Use STL priority queue:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq(stones.begin(),stones.end());
    while(pq.size() > 1) {
      int y = pq.top(); pq.pop();
      int x = pq.top(); pq.pop();
      if(x != y) { 
        y -= x;
        pq.push(y);
      }
    }
    if(pq.size())
      return pq.top();
    
    return 0;
  }
};
