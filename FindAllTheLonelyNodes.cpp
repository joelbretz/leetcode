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
/*
In a binary tree, a lonely node is a node that is the only child of its parent node. 
The root of the tree is not lonely because it does not have a parent node.*/

class Solution {
  protected:
  void dfs(TreeNode* root, vector<int>& lonely) {
    if(!root)
      return;
    
    if(!root->left && root->right) 
      lonely.push_back(root->right->val);
  
    else if(root->left && !root->right) 
      lonely.push_back(root->left->val);
    
    dfs(root->left, lonely);
    dfs(root->right, lonely);
  }
    
  public:
  vector<int> getLonelyNodes(TreeNode* root) {
    vector<int> result;
    dfs(root,result);
    return result;
  }
};
