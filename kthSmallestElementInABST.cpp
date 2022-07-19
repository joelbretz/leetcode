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
  void traverse(TreeNode* root, vector<int>& inorder) {
    if(!root)
      return;
    
    traverse(root->left, inorder );
    inorder.push_back(root->val);
    traverse(root->right, inorder);
    
  }
  public:
  int kthSmallest(TreeNode* root, int k) {
    vector<int> parsed;
    traverse(root,parsed);
    return parsed[k-1];
  }
};
