/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  protected:

  void annotate(TreeNode* currNode, TreeNode* parentNode, map<TreeNode*,TreeNode*>& parentMap) {
    parentMap[currNode] = parentNode;
    if(currNode->left)
      annotate(currNode->left, currNode, parentMap);
    if(currNode->right)
      annotate(currNode->right, currNode, parentMap);
  }

  public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    map<TreeNode*,TreeNode*> parentMap;
    // annotate tree with parentNode
    annotate(root, nullptr, parentMap);
    
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    int distance = -1;
    
    while(!q.empty()) {
      ++distance;
      //cout << "curr distance = " << distance;
      if(distance == k)
        break;
      int size = q.size();
      //cout << " levelsize = " << size << endl;
      while(size--) {
        auto curr = q.front();
        visited[curr] = true;
        q.pop();
        //cout << "   currnode = " << curr->val << endl;
        if(curr->left && !visited[curr->left])
          q.push(curr->left);
        if(curr->right && !visited[curr->right])
          q.push(curr->right);
        auto parent = parentMap[curr];
        //if(parent) 
          //cout << "  parent node = " << parent->val << endl;
        //else
          //cout << "  no parent node " << endl;
        if(parent != nullptr && !visited[parent])
          q.push(parent);
      }
    }
    vector<int> solution;
    if(distance == k) {
       while(!q.empty()) { 
         int nodeval = q.front()->val;
         q.pop();
         solution.push_back(nodeval);
       }
    }
    return solution;
  }
};
