class Solution {
  public:
  string freqAlphabets(string s) {

    string decrypted;
    int i = 0, num, len = s.length();
    while(i < len) {
      if(i+2 < len && s[i+2] == '#') {
        // decode s[i]s[i+1]
        num = stoi(s.substr(i,2));
        i += 3;
      }
      else {
        // decode s[i]
        num = stoi(s.substr(i,1));
        ++i;
      }
      num += 96;
      decrypted += (char) num; 
    }
    return decrypted;
  }
};
