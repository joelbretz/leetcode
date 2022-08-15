/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
  public:
  Node* connect(Node* root) {
    if(!root)
      return nullptr;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
      int size = q.size();
      Node* prev = nullptr;
      Node* curr;
      while(size--) {
        curr = q.front();
        q.pop();
        //cout << "curr = " << curr->val << endl; 
        if(prev != nullptr) {
          //cout << " updating " << prev->val << " to point to me" << endl;
          prev->next = curr;
        }
        //cout << "  setting prev = curr" << endl;
        prev = curr;
       
        if(curr->left) {
          //cout << "   adding " << curr->left->val << " to queue." << endl;
          q.push(curr->left);
        }
        if(curr->right) {
          //cout << "   adding " << curr->right->val << " to queue." << endl;
          q.push(curr->right);
        }
          
      }
      
      //cout << " end of level. setting " << prev->val <<"->next to nullptr" << endl;
      prev->next = nullptr;
      //cout << "   setting prev to nullptr" << endl;
      prev = nullptr;
    }
    return root;
  }
};
