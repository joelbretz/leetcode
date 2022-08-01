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
  TreeNode* traverse(TreeNode* node) {
    // obv base case
    if(!node)
      return nullptr;
    // base case: leaf
    if(!node->left && !node->right)
      return node;
    
    // recurse down
    TreeNode* leftNode = traverse(node->left);
    TreeNode* rightNode = traverse(node->right);
    
    // rotate the left side
    if(leftNode) {
      leftNode->right = node->right;
      node->right = node->left;
      node->left = nullptr;
    }
    
    if(rightNode == nullptr)
      return leftNode;
    return rightNode;
  }

  public:
  void flatten(TreeNode* root) {
    traverse(root);
  }
};
