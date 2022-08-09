class Solution {
  public:
  
  // use a monostack for this
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int ndays = temperatures.size();
    stack<int> S;
    vector<int> solution(ndays, 0);
    
    for(int day = 0; day < ndays; ++day) {
      int dailytemp = temperatures[day];
      //cout << "day " << day << ", temperature = " << dailytemp << endl;
      // pop until we find a cooler day on the stack
      while(!S.empty() && temperatures[S.top()] < dailytemp) {
        int prevday = S.top();
        S.pop();
        //cout << " found cooler day. daynum=" <<prevday << endl;
        solution[prevday] = day - prevday;
      }
      S.push(day);
    }
    return solution;
    
  }
};
