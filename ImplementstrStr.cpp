class Solution {
  public:
  // ummm.. just use string::find :) 
  int strStrSTL(string haystack, string needle) {
    if(needle.empty())
      return 0;

    auto found = haystack.find(needle);
    if(found != string::npos)
      return found;
    return -1;
  }

  // linear scan 
  int strStr(string haystack, string needle) {
    if(needle.empty())
      return 0;
    else if(needle.size() == haystack.size())
      return (needle.compare(haystack) == 0 ? 0 : -1);
    else if(needle.size() > haystack.size())
      return -1;
    
    // loop over the haystack, use hi:haystackIndex ni:needleIndex
    for(int hi = 0; hi <= haystack.size() - needle.size(); ++hi) {
      int ni = 0; // needle index
      if(needle[ni] == haystack[hi]) { // 1st char match.
        // check if we have a match
        for(ni = 1; ni < needle.size(); ++ni) {
          if(needle[ni] != haystack[hi + ni]) { // no match
            break;
          }
        }
        if(ni == needle.length())
          return hi;
      }
    }
    return -1;
  }
};
