class Solution {
  public:
  string getHint(string secret, string guess) {
    // find the chars that are in the correct position (bulls)
    // update the charactor counts as we go.
    map<char,int> secretChars;
    map<char,int> guessChars;
    int correct = 0;   // bulls
    int intersect = 0; // total number of chars in common.
    for(int i = 0; i < secret.length(); ++i) {
      secretChars[secret[i]] += 1;
      guessChars[guess[i]] += 1;
      if(secret[i] == guess[i])
        ++correct;
    }
    // the number of "cows" is the setintersection minus the correct number
    // iterate over both. if the keys match, increment the overlap by 
    // the number of that key they have in common.
    // if the keys don't match, update the iterator
    auto it1 = secretChars.begin();
    auto it2 = guessChars.begin();
    while(it1 != secretChars.end() && it2 != guessChars.end()) {
      if (it1->first < it2->first)
        ++it1;
      else if (it2->first < it1->first)
        ++it2;
      else {
        intersect += min(it1->second, it2->second);
        ++it1; ++it2;
      }
    }
    int cows = intersect - correct;
    stringstream oss;
    oss << correct << "A" << cows << "B";
    return oss.str();
  }
};
