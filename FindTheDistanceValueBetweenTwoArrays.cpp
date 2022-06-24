class Solution {
  public:

    
 // O(n^2) nested loop solution. Two thumbs down. Way down. 
  int findTheDistanceValueBruteForce(vector<int>& arr1, vector<int>& arr2, int d) {
    int rv = 0;
    for(int i = 0; i < arr1.size(); ++i) {
      for(int j = 0; j < arr2.size(); ++i) {
        int dist = abs(arr1[i] - arr2[j]);
        if ( dist <= d)
          ++rv;
      }
    }
    return rv;
  }
  
  
  // Use the "hint" and sort arr2, then use bsearch 
  // to get the closest element for each arr1[i]. 
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort arr2 
        sort(arr2.begin(), arr2.end());
        
        // remove duplications
        int prev = INT_MIN;
        int b = 0;
        while (b < arr2.size())
        {
            if (arr2[b] == prev)
                arr2.erase(arr2.begin() + b);
            else
            {
                prev = arr2[b];
                ++b;
            }
        }
        
        int count = 0;
        for (auto a: arr1)
        {
            int b1 = 0, b2 = arr2.size() - 1;
            int b_min = INT_MIN;
            
            // finding the min(abs(a - arr2[i])); where i E [0, arr2.size())
            while (!(b1 > b2))
            {
                int b = (b1+b2) >> 1;
                
                int pre = b - 1 >= 0 ? abs(a - arr2[b-1]) : INT_MAX;
                int cur = abs(a - arr2[b]);
                int nxt = b + 1 < arr2.size() ? abs(a - arr2[b+1]) : INT_MAX;
                
                if ((pre >= cur and nxt > cur) or (pre > cur and nxt >= cur))
                {
                    b_min = cur;
                    break;
                }
                else if (pre < cur)
                    b2 = b - 1;
                else
                    b1 = b + 1;
            }
            
            // check if the minimum is greater than 'd'
            if (b_min > d)
                count++;
        }
        return count;
    }
};
