class Solution {
public:
    int m, n;
  
    // <arg> i : pointer at nums
    // <arg> j : pointer at mult
    int calculate(vector<int>& nums, vector<int>& mult, vector<vector<int>>& dp, int i, int j) {
        // if we have performed all operations, then return 0
        if (j == m) return 0;
        // memoizated before - return the value here
        if (dp[i][j] != INT_MIN) return dp[i][j];
        // we can either choose an integer in `nums` the start or the end of the array
        // so we try both case and take the maximum value
        // then memoize it
        return dp[i][j] = max(
            // pick from the start
            mult[j] * nums[i] + calculate(nums, mult, dp, i + 1, j + 1),
            // pick fromt the end
            mult[j] * nums[n - 1 - j + i] + calculate(nums, mult, dp, i, j + 1)
        ); 
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = (int) nums.size(), m = (int) multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m, INT_MIN));
        // or u can return dp[0][0] after running calculate
        return calculate(nums, multipliers, dp, 0, 0);
    }
};


class Solution {
  void display(vector<int>& V) {
    for(auto i : V) 
      cout << i << " ";
    cout << endl;
  }
  
  protected:
  int calculate(vector<vector<int>>& memo, vector<int>& nums, vector<int>& multipliers, int i, int left) {
    int right = nums.size();
    if(i == multipliers.size())
      return 0;
    
    // see if we have already computed this
    if(memo[i][left] != INT_MIN)
      return memo[i][left];
    
    int u = nums[left] * multipliers[i] + calculate(memo, nums, multipliers, i + 1, left + 1);
    int v = nums[(right - 1) - (i - left)] * multipliers[i] + calculate(memo, nums, multipliers, i + 1, left );
    
    memo[i][left] = max(u,v);
    return memo[i][left];
    
    
  }
  public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size(), m = multipliers.size();
    vector<vector<int>> memo(n+1, vector<int>(m+1, INT_MIN));
    return calculate(memo, nums, multipliers, 0, 0);
    
    return 0;
  }
};
