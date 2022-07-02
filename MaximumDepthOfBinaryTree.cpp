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
//class DFSSolution {
class Solution {
  protected:
  int dfs(TreeNode* node) {
    if(!node)
      return 0;
    
    int nl = 0, nr = 0;
    if(node->left) {
        nl = dfs(node->left) + 1;
    }
    if(node->right) {
        nr = dfs(node->right) + 1;
    }
    return max(1,max(nl,nr));
  }

  public:
  int maxDepth(TreeNode* root) {
    return dfs(root);
  }
};

class BFSSolution {
  public:
  // 
  int maxDepth(TreeNode* root) {
    if(!root)
      return 0;

    int depth = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
      depth++;
      int size = q.size();
      while(size--) {
        auto node = q.front();
        q.pop();
        if(node->left)
          q.push(node->left);
        if(node->right)
          q.push(node->right);
      }
    }
    return depth;
  }
};
