class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        auto wealth = INT_MIN;
        for(auto account : accounts) {
            auto value = accumulate(account.begin(), account.end(), 0);
            wealth = max(wealth, value);
        }
        return wealth;
    }
};
