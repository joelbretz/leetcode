class Solution {
  public:
  bool possible(int k,string s, string p, vector<int>& removable) {
    for(int i = 0; i < k; i++)
      s[removable[i]]='_'; // change the first k characters to '_' 
    int i = 0, j = 0, n = s.size(), m = p.size();
    //check whether still a subsequence or not
    while(i < n && j < m) {
      if(s[i] == p[j])
        j++;
      i++;
    }
    return j == m;
  }
  
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int n = removable.size();
    int start = 0, end = n, ans=0;
    while(start <= end) {
      //here mid represents some k value, after choosing it we check whether 
      // after removing k values can we still make subsequence
      int mid = start + (end-start)/2;  
      if(possible(mid, s, p, removable)) {
        ans = mid;
        start = mid + 1;
      }
      else {
        end = mid - 1;
      }
    }
    return ans;
  }
};
