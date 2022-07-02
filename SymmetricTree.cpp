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

  bool isMirror(TreeNode* t1, TreeNode* t2) {
    if(!t1 && !t2)
      return true;
    if(!t1 || !t2) 
      return false;
    if(t1->val != t2->val)
      return false;
    bool inner = isMirror( t1->right, t2->left);
    bool outer = isMirror( t1->left, t2->right);
    return (inner & outer);
  }

  public:

  //iterative
  bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root); q.push(root);
    while(!q.empty()) {
      auto t1 = q.front(); q.pop();
      auto t2 = q.front(); q.pop();
      if(!t1 && !t2) 
        continue;
      else if(!t1 || !t2)
        return false;
      else if(t1->val != t2->val)
        return false;
      //else
      // inner
      q.push(t1->right);
      q.push(t2->left);
      // outer
      q.push(t1->left);
      q.push(t2->right);
    }
    return true;
  }

  // recursive 
  bool isSymmetricR(TreeNode* root) {
    return isMirror(root,root);
  }
};
