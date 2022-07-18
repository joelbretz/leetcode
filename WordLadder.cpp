class Solution {
  protected:
  int numWords;

  // find the distance between the words in wordlist
  void determineDistance(vector<string>& wordList, vector<vector<int>>& dist) {
    // TODO: optimize loop
    for(int i = 0; i < wordList.size() - 1; ++i) {
      for(int j = i + 1; j < wordList.size(); ++j ) {
        // compare dist between words i and j
        //cout << "compare: " << wordList[i] << ", " << wordList[j] ;//<< endl;
        for(int k = 0; k < wordList[0].size(); ++k) {
          if(wordList[i][k] != wordList[j][k]) { 
            dist[i][j] += 1;
            dist[j][i] = dist[i][j];
          }
        }
        //cout << " : dist = " << dist[i][j] << endl;
      }
    }
  }

  void printTable(vector<string>& wordList, vector<vector<int>>& dist) {
    cout << "============================" << endl;
    for(int i = 0; i < numWords; ++i) {
      cout << wordList[i] << " ";
      for(int j = 0; j < numWords; ++j) {
        cout << wordList[j] << " = " << dist[i][j] << " ";
      }
      cout << endl;
    }
  }

  public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    // verify there is work to do
    if(beginWord == endWord)
      return 0;
    // verify that the endword exists in the dictionary
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
      return 0;

    // add beginWord to the wordList
    wordList.push_back(beginWord);
    // get length of ladder
    numWords = wordList.size();

    // table of distances between words:
    vector<vector<int>> table(numWords, vector<int>(numWords, 0));
    determineDistance(wordList,table);
    printTable(wordList, table);

    // we must ALWAYS transit only 1 letter, but must be in word list.
    // take the current word, transition 1 char if it exists in wordList
    int changes = 0;
    queue<pair<string,int>> q; // word, index
    q.push({beginWord, numWords-1}); // beginWord is the last word in the dict
    while(!q.empty()) {
      changes++;
      int size = q.size();
      while(size--) {
        string currWord = q.front().first;
        int currIdx = q.front().second;
        q.pop();
        cout << "checking " << currWord << endl;
        if(currWord == endWord) // check if we're done
          return changes;
        
        for(int j = 0; j < numWords; ++j) {
          if(j == currIdx) // skip meself
            continue;
          if(table[currIdx][j] == 1) {
            cout << "  adding " << wordList[j] << " to queue." << endl;
            q.push({wordList[j],j}); // add to queue
            table[currIdx][j] = -1;  // flag that we've been here before  
            table[j][currIdx] = -1;  //  
          }
        }
      }
    } // </while q not empty>
    return 0;
  } // </ladderLength>
};
