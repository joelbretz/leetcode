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
  int maxSum;
  
  protected:
  int traverse(TreeNode* node) {
    if(!node)
      return 0;
    
    int left  = max(traverse(node->left), 0);
    int right = max(traverse(node->right), 0);
    
    int cost = node->val + left + right;
    maxSum = max(maxSum, cost);
  
    return node->val + max(left, right);
  }
  
  public:
  int maxPathSum(TreeNode* root) {
    if(!root)
      return 0;
    maxSum = INT_MIN;
    traverse(root);
    return maxSum;
  }
};
