class Solution {
  public:
  // use stringstream to parse input string
  // store reversed string in another stringstream
  // grab the string from the output stringstream.
  string reverseWords(string s) {
    stringstream sin(s);
    stringstream sout;
    string temp ;
    sin >> temp;
    while(!sin.eof()) {
      reverse(temp.begin(), temp.end());
      sout << temp << " ";
      sin >> temp;
    }
    reverse(temp.begin(), temp.end());
    sout << temp; 

    return sout.str();
  }
};
