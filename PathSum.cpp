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

  bool helper(TreeNode* root, int targetSum, int currentSum) {
    if(!root)
      return (targetSum == currentSum);

    currentSum += root->val;
    if(!root->left && !root->right)
      return (targetSum == currentSum);

    bool l = false, r = false;
    if(root->left)
      l = helper(root->left, targetSum, currentSum);
    if(root->right)
      r = helper(root->right, targetSum, currentSum);
    return (l || r);
  }
  
  public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root) return false;

    return helper(root,targetSum,0);
  }
