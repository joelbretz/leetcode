map<char,int> numerals = { {'I',1},
{'V',5},
{'X',10},
{'L',50},
{'C',100},
{'D',500},
{'M',1000}};

class Solution {
public:
    int romanToInt(string s) {
        int last = numerals[s[s.length() - 1]];
        int v = last;
        for(int i = s.length() - 2; i >= 0; --i) {
            int curr = numerals[s[i]];
            if(curr < last)
                  v -= curr;
            else
                  v += curr;
            
            last = curr;
        }
        
        return v;
    }
    
};
