class TimeMap {
  
  void printvtpairs(vector<pair<string,int>>& pairs) {
    for(auto p : pairs)
      cout << "{" << p.first << "," << p.second << "} ";
    cout << endl;
  }
  map<string,vector<pair<string,int>>> occurrences;
  public:
  TimeMap() {
    //cout << "-----------------------------" <<endl; 
  }

  void set(string key, string value, int timestamp) {
    //cout << " insert [" << key << "] {" << value << "," << timestamp << "}" << endl;
    occurrences[key].push_back({value, timestamp});
  }
  
  string get(string key, int timestamp) {
    //cout << "get(" <<key <<"," << timestamp << ")" << endl;
    auto& values = occurrences[key];
    int n = values.size();
    if(n==0)
      return "";
    //printvtpairs(values);
    int left = 0, right = n - 1;
    // find bsearch for timestamp = or <= the given one
    while(left <= right) {
      int mid = left + (right-left)/2;
      auto vtpair = values[mid];
      //cout << "  checking index " << mid << ": " << vtpair.first << "," << vtpair.second << endl;
      if(vtpair.second < timestamp)  {
        left = mid + 1;
        //cout << "  set left = " << left << endl;
      }
      else if(vtpair.second == timestamp) {
        return vtpair.first;
      }
      else {
        right = mid - 1;
        //cout << "  set right = " << right << endl;
        if(right < 0)
          return "";
      }
    }
    return values[right].first;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
