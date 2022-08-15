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
  bool traverse(TreeNode* root, TreeNode* subRoot) {

    if(root == nullptr) 
      return (subRoot == nullptr);

    if(subRoot == nullptr) 
      return (root == nullptr); 

    if(root->val == subRoot->val) {
      return traverse(root->left, subRoot->left) && traverse(root->right, subRoot->right);
    }

    return false;
  }
  
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root)
      return subRoot == nullptr;
    
    if(root->val == subRoot->val) {
      if(traverse(root,subRoot))
         return true;
    }
    
    // else
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    
        
  }
};
