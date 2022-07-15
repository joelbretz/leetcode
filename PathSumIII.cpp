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
  int count = 0;
  public:
  void dfs(TreeNode* node, long target) { 
    if(!node)
      return;

    if(node->val == target)
      count += 1;

    dfs(node->left, target - node->val); 
    dfs(node->right, target - node->val);
    return;
  }

  int pathSum(TreeNode* root, int targetSum) {
    if(!root)
      return 0;
    dfs(root,targetSum);
    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);
    return count;
  }
};
