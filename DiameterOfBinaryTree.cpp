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
  protected:
  int solver(TreeNode* root, int& d) {
    
    if(!root)
      return 0;
    
    int depth_l = solver(root->left, d);
    int depth_r = solver(root->right, d);
    
    d = max(d, depth_l + depth_r);
    return max(depth_l, depth_r) + 1;
    
  }
  
  public:
  int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    solver(root, diameter);
    return diameter;
  }
};
