class Trie {
  protected:
  struct TrieNode {
    vector<TrieNode*> children;
    bool endNode;
    
    TrieNode() : children(26, nullptr), endNode(false) {};

    inline bool containsKey(char c) { return children[c - 'a'] != nullptr; }
    inline TrieNode* get(char c) { return children[c - 'a']; }
    inline void put(char c, TrieNode* node) { children[c - 'a'] = node; }
    inline void setEnd() { endNode = true; }
    inline bool isEnd() { return endNode; }

  };
  
  TrieNode* searchPrefix(string word) {
    TrieNode* node = root;
    for(int i = 0; i < word.length(); ++i) {
      char c = word[i];
      if(node->containsKey(c))
        node = node->get(c);
      else
        return nullptr;
    }
    return node;
  }

  TrieNode* root;
  public:
  Trie() {
    root = new TrieNode;
  }

  void insert(string word) {
    TrieNode* node = root;
    for(int i = 0; i < word.length(); ++i) {
      char c = word[i];
      if(!node->containsKey(c))
        node->put(c, new TrieNode);
      node = node->get(c);
    }
    node->setEnd();
  }

  bool search(string word) {
    TrieNode* node = searchPrefix(word);
    return node != nullptr && node->isEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* node = searchPrefix(prefix);
    return node != nullptr;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
