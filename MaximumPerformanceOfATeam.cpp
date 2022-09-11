class Solution {
  
  static bool compare(pair<int,int>& a, pair<int,int>& b) {
    if(a.first > b.first)
      return true;
    return false;
  }
  void print(vector<pair<int,int>>& vp) {
    for(auto p : vp) {
      cout << "{" << p.first << "," << p.second << "} ";
    }
    cout << endl;
  }
    
  public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    
    // convert speed/efficiency vectors into a vector of {eff/speed} pairs
    vector<pair<int,int>> worker;
    for(int i = 0; i < n; ++i) 
      worker.push_back({efficiency[i], speed[i]});
   
    // sort by efficiency in descending order
    sort(worker.begin(), worker.end(), compare);
    // use a pq (as minheap) to store the sum
    priority_queue<int, vector<int>, greater<int>> heap;
    long sumOfSpeed = 0, result = 0;
    for(auto w : worker) {
      heap.push(w.second); // speed 
      sumOfSpeed += w.second;
      
      // keep pq trimmed to k people
      if(heap.size() > k) {
        sumOfSpeed -= heap.top();
        heap.pop();
      }
      result = max(result, sumOfSpeed * w.first);
    }
    
    int modulo = 1e9 + 7; 
    return (int) (result % modulo);
    
  }
};
