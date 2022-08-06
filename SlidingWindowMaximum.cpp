class Solution {
  public:
  // use a priority to hold the current max and it's position
  // check remaining values against the front of the priority queue
  // pop it when the top element came k 
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    priority_queue<pair<int,int>> pq;  // value, position
    // populate pq with current window
    for(int i = 0; i < k; i++)
      pq.push({nums[i],i});

    // grab front, don't worry about age for this time.
    ans.push_back(pq.top().first);

    // loop over remaining elements:
    for(int i = k; i < nums.size(); i++){
      // push the current value onto the pq
      pq.push({nums[i],i});
      // remove elements that are > k elements old 
      while(!pq.empty() && pq.top().second < i - k + 1)
        pq.pop();
      // grab next piece of our solution
      ans.push_back(pq.top().first);
    }
    return ans;
  }
};
