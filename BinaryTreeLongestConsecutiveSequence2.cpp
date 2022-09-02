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
  void dfs(TreeNode* node, TreeNode* parent, int currLen, int &maxLen) {
    if(node == nullptr)
      return;
    
    if(parent == nullptr)
      currLen = 1;
    else if(node->val == parent->val + 1)
      currLen += 1;
    else
      currLen = 1;
    maxLen = max(maxLen, currLen);
    
    dfs(node->left, node, currLen, maxLen);
    dfs(node->right, node, currLen, maxLen);
      
    
  }
  public:
  int longestConsecutive(TreeNode* root) {
    int curr = 0, maxLen = 0;
    dfs(root, nullptr, curr, maxLen);
    return maxLen;
      
  }
};
