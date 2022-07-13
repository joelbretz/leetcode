//BalancedBinaryTree.cpp
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
  
  int solve(TreeNode* node, bool& bal) {
    if(!node || !bal)
      return 0;
    
    int l_height = solve(node->left, bal);
    int r_height = solve(node->right, bal);
    
    if(abs(l_height - r_height) > 1)
      bal = false;
    
    return max(l_height, r_height) + 1;
  }
  
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
      solve(root,balanced);
      return balanced;
    }
};
