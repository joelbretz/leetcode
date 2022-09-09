class Solution {
  protected:
  // sort pairs in ascending order of their attack, 
  // then in descending order of the defense value.
  static bool compare(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]) 
      return( a[1] > b[1] );
    
    return (a[0] < b[0]);
  }

  void print(vector<vector<int>>& array) {
    for(auto elem : array) {
      cout << "[" << elem[0] << "," << elem[1] << "] ";
    }
    cout << endl;
  }

  public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), compare);
    int numWeak = 0, maxD = 0;
    for(int i = properties.size() - 1; i >= 0; --i) {
      if(properties[i][1] < maxD)
        numWeak++;
      maxD = max(maxD, properties[i][1]);
    }
    return numWeak;
  }

  // ok, the obv brute force n^2 solution: expect TLE.
  int numberOfWeakCharactersBF(vector<vector<int>>& properties) {
    int n = properties.size();
    int weak = 0;
    vector<int> isWeak(n, 0);
    for(int i = 0; i < n; ++i ) {
      for(int j = 0 ; j < n; ++j) {
        if(properties[i][0] < properties[j][0] && properties[i][1] < properties[j][1]) {
          isWeak[i] = 1;
          continue;
        }
      }
    }
    weak = accumulate(isWeak.begin(), isWeak.end(), 0);
    return weak;
  }
};
