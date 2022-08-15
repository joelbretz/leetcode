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
  vector<vector<int>> verticalOrder(TreeNode* root) {

    vector<vector<int>> result;
    if(!root)
      return result;
    map<int,vector<int>> table;  // column #, nodes in column
    
    queue<pair<TreeNode*,int>> q;  // Node, column
    int column = 0, leftmostCol = 0, rightmostCol = 0; 
    q.push({root,column});
    
    while(!q.empty()) {
      TreeNode* curr = q.front().first;
      column = q.front().second;
      q.pop();
      table[column].push_back(curr->val);
      leftmostCol = min(leftmostCol, column);
      rightmostCol = max(rightmostCol, column);
      
      if(curr->left) 
        q.push({curr->left, column - 1});
      if(curr->right)
        q.push({curr->right, column + 1});
      
    }
    for(int col = leftmostCol; col < rightmostCol + 1; ++col) {
        result.push_back(table[col]);
    }
    return result;
  }
};
