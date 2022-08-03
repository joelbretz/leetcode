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
  int widthOfBinaryTree(TreeNode* root) {

    if(!root)
      return 0;

    queue<pair<TreeNode*,unsigned long>> q;
    q.push({root,0});
    unsigned long maxWidth = 0;

    while(!q.empty()) {

      pair<TreeNode*,unsigned long> start = q.front();
      unsigned long size = q.size();
      pair<TreeNode*,unsigned long> curr; 
      while(size--) {
        curr = q.front();
        q.pop();
        TreeNode* node = curr.first; unsigned long colIndex = curr.second;
        if(node->left) 
          q.push({node->left, 2*colIndex});
        if(node->right)
          q.push({node->right, 2*colIndex+1});
      }  
      maxWidth = max(maxWidth, curr.second - start.second + 1);
    }
    return maxWidth;
  }
};
