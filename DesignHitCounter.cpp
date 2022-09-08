class HitCounter {
  int total;
  queue<pair<int,int>> q;
  public:
  HitCounter() : total(0) {

  }

  void hit(int timestamp) {
    if(q.empty() || q.back().first != timestamp)
      q.push({timestamp,1});
    else
      q.back().second++;
    ++total;
          
  }

  int getHits(int timestamp) {
    while(!q.empty()) {
      int d = timestamp - q.front().first;
      if(d >= 300) {
        total -= q.front().second;
        q.pop();
      }
      else
        break;
    }
    return total;
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
