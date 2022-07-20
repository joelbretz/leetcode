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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    // double bfs
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(p);
    q2.push(q);
    while(!q1.empty() && !q2.empty()) {
      TreeNode* node1 = q1.front();
      TreeNode* node2 = q2.front();
      q1.pop();
      q2.pop();
      if(!node1 && !node2)
        continue; //return true;
      else if((!node1 && node2) || (node1 && !node2))
        return false;
      else if(node1->val != node2->val)
        return false;
      else if(node1->left && !node2->left )
        return false;
      else if(!node1->left && node2->left )
        return false;
      else if(node1->right && !node2->right)
        return false;
      else if(!node1->right && node2->right)
        return false;
      else {
        q1.push(node1->left);
        q1.push(node1->right);
        q2.push(node2->left);
        q2.push(node2->right);
      }
    }
    
    return true;
  }
};
