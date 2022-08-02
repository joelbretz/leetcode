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
  map<int,int> inorderMap;
  int preorderPtr;
  
  TreeNode* construct(vector<int>& preorder, int left, int right) {
    if(left > right)
      return nullptr;
    
    auto nodeVal = preorder[preorderPtr];
    preorderPtr++;
    TreeNode *node = new TreeNode(nodeVal);
    
    int pos = inorderMap[nodeVal];
    node->left = construct(preorder, left, pos - 1);
    node->right = construct(preorder, pos + 1, right);
    
    return node;
  }
  
  public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
    preorderPtr = 0;
    for(int i = 0; i < inorder.size(); ++i) {
      inorderMap[inorder[i]] = i;
    }
    TreeNode *rebuilt = 
      construct(preorder, 0, preorder.size() - 1);
    
    return rebuilt;
  }
};
