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
  void dfs(TreeNode* root, int currMax, int& numGood) {
    
    if(currMax <= root->val)
      numGood++;
    
    if(root->left != nullptr) 
      dfs(root->left, max(root->val,currMax), numGood);
    
    if(root->right != nullptr)
      dfs(root->right, max(root->val,currMax), numGood);
    
  }
  public:
  int goodNodes(TreeNode* root) {
    if(!root)
      return 0;
    
    int largest = INT_MIN;
    int count = 0;
    dfs(root, largest, count);
    return count;
  }
};
