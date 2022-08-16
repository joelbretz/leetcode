class Solution {
  protected:
  void printMap(map<int,int>& M) {
    cout << "diff : n_tasks" << endl;
    for(auto entry : M) {
      cout << entry.first << " : " << entry.second << endl;
    }
  }
  
  public:
  int minimumRounds(vector<int>& tasks) {
    map<int,int> taskmap; // difficulty, num_tasks
    // create map/hash
    for(int i = 0; i < tasks.size(); ++i) {
      taskmap[tasks[i]]++;
    }
    
    //printMap(taskmap);
    
    int rounds = 0;
    for(auto elem : taskmap) {
      if(elem.second == 1)
        return -1;
      else if(elem.second == 2 || elem.second == 3)
        rounds += 1;
      else {
        rounds += ceil(elem.second / 3.0f);
      }
    }
    return rounds ;
  }
};
