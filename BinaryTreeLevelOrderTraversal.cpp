/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
  vector<vector<int>> levelOrder(TreeNode* root) {

    vector<vector<int>> rv;
    if(!root)
      return rv;

    // use a queue for a bfs
    queue<TreeNode*> nodeQ;
    nodeQ.push(root);
    
    while(!nodeQ.empty()) {
      int levelSize = nodeQ.size();
      vector<int> v;
      //cout << "levelSize = " << levelSize << endl;
      while(levelSize--) {
        TreeNode* curr = nodeQ.front();
        nodeQ.pop();
        v.push_back(curr->val);
        
        if(curr->left)
          nodeQ.push(curr->left);
        if(curr->right) 
          nodeQ.push(curr->right);
      }
      rv.push_back(v);
    }
    return rv;
  }
};
