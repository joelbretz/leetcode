/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
  public:
  
  
  // iterative, which is more intuitive to me and it saves the overhead
  // of all the function calls.
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int a = p->val, b = q->val;
    TreeNode* curr = root;
    while(curr != nullptr) {
      int v = curr->val;
      if(a < v && b < v) 
        curr = curr->left;
      else if(a > v && b > v)
        curr = curr->right;
      else
        return curr;
    }
    return nullptr;
  }
    // recursive solution
  TreeNode* lowestCommonAncestorR(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
      return nullptr;
    if(p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left,p,q);
      
    if(p->val > root->val && q->val > root->val)
      return lowestCommonAncestor(root->right,p,q);
    
    return root;
  }
};
