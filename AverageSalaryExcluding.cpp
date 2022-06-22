class Solution {
    public:
    // naive solution add em up, keep track of min/max
    double average(vector<int>& salary) {
        int noob = INT_MAX;
        int star = INT_MIN;
        long sum = 0;
        for(auto s : salary) {
            noob = min(s,noob);
            star = max(s,star);
            sum += s;
        }
        sum -= noob; sum -= star;
        return ((sum * 1.0) / (salary.size() - 2));
    }
};
