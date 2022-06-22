// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int upper = n; 
        int lower = 0;
        // binary search versions
        long lo = 0, hi = n, mid;
        while(lo <= hi) {
            mid = (lo + hi) / 2;
            if(isBadVersion(mid)) {
                // bad comes before me.
                hi = mid - 1;
                //upper = min(upper,mid);
                if(mid < upper)
                    upper = mid;
            }
            else {
                // bad comes later
                lo = mid + 1;
                //lower = max(lower,mid);
                if(mid > lower)
                    lower = mid;
            }
        }
        return lower + 1;
    }
};
