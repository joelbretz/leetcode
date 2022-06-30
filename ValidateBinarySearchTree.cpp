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

  TreeNode* prev;

  bool inOrder(TreeNode* root) {
    if(!root)
      return true;

    if(!inOrder(root->left))
      return false;

    if(prev!=nullptr && root->val <= prev->val)
      return false;
    prev = root;
    
    return inOrder(root->right);
  }
  public:

  bool isValidBST(TreeNode* root) {
    prev = nullptr;
    return inOrder(root);
    cout << endl;
    return true;
  }
};
