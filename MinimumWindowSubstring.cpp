class Solution {
  public:
  string minWindow(string s, string t) {
    int sLen = s.length(), tLen = t.length(); 
    if(sLen == 0 || tLen == 0 || (tLen > sLen))
      return "";
    // count of charactors in t
    map<char,int> substrCount;
    for(auto c : t) 
      substrCount[c]++;
    // number of matches on letter counts
    int required = substrCount.size();
    // this is "flag" it will have the same value as "required"  when we have a valid subwindow of s
    int matched = 0; 
    // window pointers
    int left = 0; int right = 0;
    // count of characters in the current window of s
    map<char,int> windowCount; 
    
    vector<int> minWindow = { -1, 0, 0 }; // length, left, right 
    while(right < s.length()) {
      // get the next char in s
      char lc = s[left];  // store left char 
      char rc = s[right]; // store right char 
      windowCount[rc]++;       // update the window count of right char
      //cout << "[" << left  << "," << right << "] : " << lc << "," << rc << " num_" << rc << "=" << windowCount[rc] << endl; 
      // check if we have enough of them
      if(windowCount[rc] == substrCount[rc]) {
        matched++;
        //cout << "  window with " << rc << " meets " << matched << " of " << required << " criteria" << endl;
      }
     
      while((left <= right) && (matched == required)) {
        //cout << "** [" << left  << "," << right << "] :" ;
        if(minWindow[0] == -1 || ((right-left+1) < minWindow[0])) {
          minWindow = {right-left+1, left, right};
        }
        //cout << "  FOUND " << t << " in " << s.substr(left, (right-left) + 1) << endl;
        // remove left from windowCount
        //cout << "  dropping " << lc << endl;
        lc = s[left];
        windowCount[lc]--;
        // remove the leftmost
        if(windowCount[lc] < substrCount[lc]) {
          matched--;
        }
        left++;
      }
      right++;
    }
    if(minWindow[0] == -1)
      return "";
    
    return s.substr(minWindow[1],minWindow[0]);
  }
};
