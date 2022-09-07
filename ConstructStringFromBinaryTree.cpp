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
  
  // this is a weird pre-order traversal.  
  void traverse(TreeNode* node, string& cur) {
    if(node == nullptr)
      return;

    cur += to_string(node->val); // pre-order, all node first.
    
    // check if it's a leaf and bail if it is.
    if(node->left == nullptr && node->right == nullptr)
      return;
    
    // check to see if we only go left, and add the proper parens
    // around left traversal
    if(node->right == nullptr) {
      cur += '(' ; 
      traverse(node->left, cur);
      cur += ')';
      return;
    }
    // otherwise, go left and right.
    //    add parens in between traversals
    cur += '(' ;
    traverse(node->left, cur);
    cur += ")(" ;
    traverse(node->right, cur);
    cur += ')';
  }

  public:
  string tree2str(TreeNode* root) {
    if(!root) 
      return "";
    string result;
    traverse(root, result);
    return result;
  }
};
