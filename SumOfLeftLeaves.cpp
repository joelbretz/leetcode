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
  int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    while(root) {
      if(!root->left)
        root = root->right;
      else {
        TreeNode* prev = root->left;
        if(!prev->left && !prev->right)
          sum += prev->val;
       
        while(prev->right && prev->right != root)
          prev = prev->right;
        
        if(!prev->right) {
          prev->right = root;
          root = root->left;
        }
        else {
          prev->right = nullptr;
          root = root->right;
        }
      }
    }
    return sum;
  }
};
