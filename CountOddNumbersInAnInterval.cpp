class Solution {
public:
    // simple loopy way.
    int countOdds2(int low, int high) {
        int n = 0;
        for(int i = low; i <= high; ++i) {
            if( i&0x1 == 0x1)
                ++n;
        }
        return n;
    }
    
    // use the difference between them:
    // if either endpoint is odd, n = delta/2 + 1
    // else just delta/2
    
    int countOdds(int low, int high) {
    
        int delta = high - low;
        if( ( low & 0x1)  || (high & 0x1))
            return ((delta / 2) + 1);
        else
            return delta / 2;
    }
    
};
