
class Solution {
  public:
  int leastInterval(vector<char>& tasks, int n) {
    map<char, int> taskCount;
    // largest number of occurences
    int mostFreq = 0;
    // num of tasks with highest frequency
    int numMostFreq = 0;
    for(auto t : tasks) {
      taskCount[t]++;
      mostFreq = max(mostFreq,taskCount[t]);
    }
    
    for(auto it : taskCount) {
      if(it.second == mostFreq)
        numMostFreq++;
    }
    int len = tasks.size();
    return max(len, ((1+n)*(mostFreq-1)+numMostFreq));
  }
};
