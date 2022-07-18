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

  // determine words that are 1 away from the current word and create a list 
  // of indices that can be used in the bfs later
  void findAdjacentWords(vector<string>& wordList, vector<vector<int>>& adj) {

    for(int i = 0; i < wordList.size(); ++i) {
      for(int j = i + 1; j < wordList.size(); ++j) {
        int d = 0;
        for(int k = 0; k < wordList[0].size(); ++k) {
          if(wordList[i][k] != wordList[j][k])
            ++d;
        }
        if(d == 1) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
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
  
  void printAdjList(vector<string>& wordList, vector<vector<int>>& adj) {
    for(int i = 0; i < wordList.size(); ++i) {
      cout << wordList[i] << " : " ;
      for(int j = 0; j < adj[i].size(); ++j) {
        cout << wordList[adj[i][j]] << " " ;
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
    
    // adjacency list
    vector<vector<int>> adjList(numWords, vector<int>());
    findAdjacentWords(wordList,adjList);
    //printAdjList(wordList,adjList);
    // need to keep track of visited indices in the adjList approach
    unordered_set<int> seen;
    
    // execute a BFS on words that are 1-away (adjacent)
    int changes = 0;
    queue<pair<string,int>> q; // word, index
    q.push({beginWord, numWords-1}); // beginWord is the last word in the dict
    seen.insert(numWords-1);
    while(!q.empty()) {
      changes++;
      int size = q.size();
      while(size--) {
        string currWord = q.front().first;
        //int currIdx = q.front().second;
        int idx = q.front().second;
        q.pop();
        //cout << "checking " << currWord << endl;
        if(currWord == endWord) // check if we're done
          return changes;

        for(int j = 0; j < adjList[idx].size(); ++j) {
          if(seen.find(adjList[idx][j]) != seen.end())
            continue;
          else {
            q.push({wordList[adjList[idx][j]], adjList[idx][j] });
            seen.insert(adjList[idx][j]);
          }
        }
      }
    } // </while q not empty>
    return 0;
  } // </ladderLength>
};
