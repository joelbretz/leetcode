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
  void traverse(TreeNode* node, map<int,int>& valueCount, int &paths) {
    if(!node) 
      return;
    // update occurence
    valueCount[node->val]++;
    
    // if i am a leaf, check if we have a valid solution:
    if(!node->left && !node->right) {
      int nOdd = 0; //, nEven = 0;
      for(auto elem : valueCount) {
        if((elem.second & 0x1) == 0x1) {
          nOdd++;
        }
      }
      if(nOdd <= 1)
        ++paths;
    }
    
    traverse(node->left, valueCount, paths);
    traverse(node->right, valueCount, paths);
    
    // back track
    valueCount[node->val]--; 
  }
  
  public:
  int pseudoPalindromicPaths (TreeNode* root) {
    map<int,int> mp; 
    int paths = 0;
    traverse(root, mp, paths);
    return paths;
  }
};
