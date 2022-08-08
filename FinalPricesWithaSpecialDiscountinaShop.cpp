
class Solution {

  int getPrice(vector<int>& prices, int i) {
    int j = i + 1;
    while(j < prices.size()) {
      if(prices[j] <= prices[i])
        return(prices[i] - prices[j]);
      ++j;
    }
    return prices[i];
  }
  public:
  // lets do BF and see if we notice anything
  vector<int> finalPrices(vector<int>& prices) {
    vector<int> result;
    for(int i = 0; i < prices.size(); ++i) 
      result.push_back(getPrice(prices,i));
    return result;
  }
}
