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
  bool isLeaf(TreeNode* node) {
    if(!node)
      return false;
    if(!node->left && !node->right)
      return true;
    return false;
  }
  
  public:
  vector<vector<int>> findLeaves(TreeNode* root) {

    queue<TreeNode*> q;
    vector<vector<int>> solution; 
    while(!isLeaf(root)) {
      //cout << "=== top of the order. ===" << endl;
      q.push(root);
      vector<int> leaves;
      while(!q.empty()) {
        auto node = q.front();
        //cout << "curr node = " << node->val << endl;
        q.pop();
        if(isLeaf(node->left)) {
          //cout << " left child " << node->left->val << " is a leaf." << endl;
          leaves.push_back(node->left->val);
          node->left = nullptr;
        }
        else {
          cout << " push left child." << endl;
          if(node->left)
            q.push(node->left);
        }

        if(isLeaf(node->right)) {
          //cout << " right child " << node->right->val << " is a leaf." << endl;
          leaves.push_back(node->right->val);
          node->right = nullptr;
        }
        else { 
          //cout << " push right child." << endl;
          if(node->right)
            q.push(node->right);
        }
      }
      solution.push_back(leaves);
    }
    solution.push_back({root->val});
    return solution;
  }
};
