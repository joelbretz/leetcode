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
  bool findTarget(TreeNode* root, int k) {

    unordered_set<int> S;
    queue<TreeNode*> q;
    //S.insert(root->val);
    q.push(root);
    while(!q.empty()) {
      auto node = q.front();
      q.pop();
      int other = k - node->val;
      if(S.find(other) != S.end())
        return true;
      S.insert(node->val);
      if(node->left)
        q.push(node->left);
      if(node->right)
        q.push(node->right);
    }
    return false;
  }
};
