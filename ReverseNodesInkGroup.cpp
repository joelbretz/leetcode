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
  // try using a stack to push k nodes at a time and 
  // use stack property of LIFO to reverse them. 
  ListNode* reverseKGroup(ListNode* head, int k) {
    stack<ListNode*> nodeStack;
    ListNode* dummy = new ListNode(-1,head);
    ListNode* p1 = dummy->next;
    ListNode* p2 = dummy;
    
    while(p1 != nullptr) { // && (curr->next != nullptr)
      // push k nodes on the stack
      int i;
      for(i = 0; i < k; ++i) {
        nodeStack.push(p1);
        if(p1)
          p1 = p1->next;
      }

      // pop em off and fix stuff up.
      ListNode* topNode = nodeStack.top(); 
      // check if there are k nodes to reverse.
      if(topNode == nullptr) {
        while(nodeStack.size() > 1) 
          nodeStack.pop();
        p2->next = nodeStack.top();
        nodeStack.pop();
      }
      else {
        for(i = 0; i < k; ++i) {
          p2->next = nodeStack.top();
          nodeStack.pop();
          p2 = p2->next;
        }
        p2->next = p1;
      }
    }
    return dummy->next; 
  }
};
