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
  
  // Iterative solution for practice
  TreeNode* searchBST(TreeNode* root, int val) {
    
    TreeNode* curr = root;
    while(curr != nullptr) { 
      if(curr->val > val)
        curr = curr->left;
      else if(curr->val < val)
        curr = curr->right;
      else
        return curr;
    }
    return nullptr;
  }
  // 2nd semester CS recursive solution
  TreeNode* searchBSTRecursive(TreeNode* root, int val) {
    if(!root)
      return nullptr;

    if(root->val > val) 
      return searchBST(root->left, val);
    else if(root->val < val) 
      return searchBST(root->right, val);
    return root;

  }
};
