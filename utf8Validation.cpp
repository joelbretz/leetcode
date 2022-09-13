class Solution {
  public:
  bool validUtf8(vector<int>& data) {
    int bytes = 0; //, n = data.size();
 
    for(auto n : data) {
      if(bytes == 0) {
        if((n >> 5) == 0b110) 
          bytes = 1;
        else if((n >> 4) == 0b1110)
          bytes = 2;
        else if((n >> 3) == 0b11110)
          bytes = 3;
        else if((n >> 7) != 0)
          return false;
      }
      else {
        if((n >> 6) != 0b10)
          return false;
        else 
          --bytes;
      }
    }
    return (bytes == 0);
  }
};
