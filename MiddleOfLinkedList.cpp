/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  // non recursive, O(n) in time and space
  // just push the nodes into a vector and then return 
  // the middle element.
  ListNode* middleNodeUseVector(ListNode* head) {
    vector<ListNode*> nodes;
    ListNode* curr = head;
    while(curr) {
      nodes.push_back(curr);
      curr = curr->next;
    }
    return nodes[nodes.size() / 2.0];
  }
 
  // Two pointer solution 
  ListNode* middleNode(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
