class Solution {
  public:
  string mergeAlternately(string word1, string word2) {
    int p = 0;
    string merged;
    int len1 = word1.length(), len2 = word2.length();
    //cout << word1 << "," << word2 << endl; 
    while(len1 && len2 ) {
      merged += word1[p];
      merged += word2[p];
      ++p; --len1; --len2; 
      //cout << "merged,p,l1,l2 = " << merged << "," << p << ","<< len1 << ","<< len2 << endl;
    }
    //cout << "loop exit. len1=" << len1 << ", len2=" << len2 << endl;
    if(len1) {
      merged += word1.substr(word2.length(), len1);
    }
    else if(len2) {
      merged += word2.substr(word1.length(), len2);
    }
    return merged;
  }
};
