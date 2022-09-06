class Solution {
  public:
  string convert(string s, int numRows) {
    
    if(numRows == 1)
      return s;
    
    vector<string> rows(numRows, "");
    string solution; 
   
    
    bool countup = true;
    int r = 0;
    for(auto ch : s) {
      rows[r] += ch;
      if(countup) {
        r++;
        if(r == numRows) {
          countup = false;
          r = numRows - 2;
        }
      }
      else { // down
        r--;
        if(r < 0) {
          countup = true;
          r = 1;
        }
      }
    }
    
    for(auto row : rows) 
      solution += row;
    
    return solution;
  }
};
