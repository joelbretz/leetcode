class Solution {
public:
    // sort and compare adjacent indices.
    // or use set.
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> S;
        for(auto n : nums) {
            auto i = S.insert(n);
            if(i.second == false)
                return true;
        }
        return false;
    }
};
