class Solution {
public:
    // 
    bool canConstruct(string ransomNote, string magazine) {
    
        int count[26] = { 0 };
        for(auto c : magazine) {
            count[c - 'a'] += 1;
        }
        
        for(auto c : ransomNote) {
            if(count[c - 'a'] > 0)
                count[c - 'a'] -= 1;
            else
                return false;
        }
        return true;
    }
};
