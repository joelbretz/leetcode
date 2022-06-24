class Solution {
  public:

  // single pass, finds the valley
  // and checks for profit if we're not at a valley.
  int maxProfit(vector<int>& prices) {
    int valley = INT_MAX;
    int profit = 0;

    for(int i = 0; i < prices.size(); ++i)  {
      if(prices[i] < valley)
        valley = prices[i];
      else if(prices[i] - valley > profit)
        profit = prices[i] - valley;

    }
    return profit;
  }

  // brute force, O(n^2), maximize profit by comparing
  // every buy with every sell point
  int maxProfit2(vector<int>& prices) {
    int profit = 0;
    for(int i = 0; i < prices.size() - 1; ++i ) {
      for(int j = i; j < prices.size(); ++j) {
        int val = prices[j] - prices[i];
        profit = max(profit,val);
      }
    }
    return profit;
  }
};
