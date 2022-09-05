class Solution {
  public:
  vector<vector<int>> levelOrder(Node* root) {
     
    vector<vector<int>> output;
    if(!root) return output;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      int size = q.size();
      vector<int> level;
      while(size--) {
        auto node = q.front();
        q.pop();
        level.push_back(node->val);
        for(auto child : node->children)
          q.push(child);
      }
      output.push_back(level);
    }
    return output;
  }
};
