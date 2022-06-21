class Solution {
public:
    
   static bool by_value(pair<int,int>&a, pair<int,int>& b) {
        if(a.second < b.second)
            return true;
        else if(a.second == b.second) {
            return a.first < b.first;
        } 
        return false;
    }
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,int> rowStrength;
        // calculate the strength of each row
        for(int r = 0; r < mat.size(); ++r) { 
            for(int c = 0; c < mat[r].size(); ++c) {
                rowStrength[r] += mat[r][c];
            }
        }
        // sort them by value
        vector<pair<int,int>> weakest(rowStrength.begin(), rowStrength.end());
        sort(weakest.begin(), weakest.end(), by_value);
        
        // copy over first k in weakest
        vector<int> answer;
        for(int i = 0; i < k; ++i) {
            answer.push_back(weakest[i].first);
        }
        
        return answer;
    }
};
