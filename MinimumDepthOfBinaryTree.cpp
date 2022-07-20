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
  int minDepth(TreeNode* root) {
    if(!root)
      return 0;

    int minDepth = INT_MAX;
    int depth = 0; // depth of root will be 1
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      int size = q.size();
      depth += 1;
      while(size--) {
        auto node = q.front();
        q.pop();
        if(!node->right && !node->left) {
          minDepth = min(minDepth, depth);
        }
        if(node->left)
          q.push(node->left);
        if(node->right)
          q.push(node->right);
      }
    } // </ while(!q.empty()) >
    return minDepth;
  }
};
