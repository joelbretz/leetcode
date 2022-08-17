class Solution {
  public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    
    int n = plantTime.size();
    
    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < n; i++)
      pq.push({growTime[i], plantTime[i]});
    
    int daysNeededToPlant = 0, totalDays = 0;
    while(!pq.empty()) {
      auto curr = pq.top();
      pq.pop();
      daysNeededToPlant += curr.second;
      int grow = daysNeededToPlant + curr.first + 1;
      totalDays = max(grow, totalDays);
    }
    return totalDays - 1;
  }
};
