class Solution {
  protected:
  map<int, string> numeralMap = {
    {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
    {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, 
    {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
  };
  public:
  string intToRoman(int num) {

    string result;
    for(auto i = numeralMap.rbegin(); i != numeralMap.rend(); ++i) {
      while(num >= i->first) {
        result += i->second;
        num -= i->first;
      }
    }
    return result;
  }
};
