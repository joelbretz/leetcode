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
  pair <int, int> dfs(TreeNode *root, int &ret, int p = 0) {
    if (!root) 
      return {0, 0};
    auto [l1, l2] = dfs(root->left, ret, root->val);
    auto [r1, r2] = dfs(root->right, ret, root->val);
    ret = max({ret, l1 + 1 + r2, l2 + 1 + r1});
    if (p - root->val ==  1)
      return {max(l1, r1) + 1, 0};
    if (p - root->val == -1)
      return {0, max(l2, r2) + 1};
    return {0, 0};
  }



  int longest; 
  pair<int,int> longestPath(TreeNode* node) { 
    if(!node)
      return {0,0};

    int inc = 1, dec = 1;
    if(node->left) {
      auto left = longestPath(node->left);
      if(node->val == node->left->val + 1)
        dec = left.second + 1;
      else if(node->val == node->left->val - 1)
        inc = left.first + 1;
    }
    if(node->right) {
      auto right = longestPath(node->right);
      if(node->val == node->right->val + 1) 
        dec = right.second + 1;
      else if(node->val == node->right->val - 1) 
        inc = right.first + 1;
    }
    longest = max(longest, inc + dec - 1);
    return {inc, dec};
  }

  public:
  int longestConsecutive2(TreeNode* root) {
    longest = 0;
    longestPath(root);
    return longest;
  }

  int longestConsecutive(TreeNode* root) {
    int ret = 0;
    dfs(root, ret);
    return ret;
  }

};
