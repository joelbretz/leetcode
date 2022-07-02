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
  void traverse(TreeNode* root, vector<int>& postOrder) {
    if(!root)
      return;
    
    traverse(root->left, postOrder);
    traverse(root->right, postOrder);
    postOrder.push_back(root->val);
  }
  
  public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    traverse(root,result);
    return result;
  }
};
