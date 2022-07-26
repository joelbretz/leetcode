class Solution {
  protected:
  map<char,string> buttonMap = { {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"}, {'6',"mno"},
                    {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
  
  
  void build(string& digits, int currDigit, string& combo, vector<string>& solution) {
   // cout << "build( digits, " << currDigit << ", " << combo << endl; 
    if(currDigit == digits.length()) {
      solution.push_back(combo);
      return;
    }
    char c = digits[currDigit];
    for(int i = 0; i < buttonMap[c].length(); ++i) {
      combo.push_back(buttonMap[c][i]);
      build(digits, currDigit + 1, combo, solution);
      combo.pop_back();
    }
  }
  
  public:
  vector<string> letterCombinations(string digits) {
    if(digits.length() == 0)
      return {};
    
    vector<string> solution;
    string combo;
    build(digits,0,combo,solution); 
    return solution;
  }
};
