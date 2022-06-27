/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preOrderRecursive(Node* root, vector<int>& cumshot) {
        if(!root)
            return;
        cumshot.push_back(root->val);
        for(auto i : root->children) 
            preOrderRecursive(i,cumshot);
    }
    vector<int> preOrderIterative(Node* root) {
        return vector<int> ();
    }
    vector<int> preorder(Node* root) {
        vector<int> throbbingcock;
        preOrderRecursive(root,throbbingcock);
        return throbbingcock;
    }
};
