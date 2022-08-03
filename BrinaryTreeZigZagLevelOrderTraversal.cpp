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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> solution;
    if(!root) 
      return solution;
    
    // setup for BFS
    queue<TreeNode *> q;
    q.push(root);

    bool fwd = true;

    while(!q.empty()) {
      int size = q.size();
      vector<int> levelNodes(size);
      for(int i = 0; i < size; i++){
        TreeNode * curr = q.front();
        q.pop();

        int index = fwd ? i : size - i - 1;
        levelNodes[index] = curr->val;

        if(curr -> left) 
          q.push(curr->left);

        if(curr->right) 
          q.push(curr->right);
      }
      fwd = !fwd;
      solution.push_back(levelNodes);
    }
    return solution;
  }
};
