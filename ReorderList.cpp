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
  void reorderList(ListNode* head) {
    stack<ListNode*> S;
    ListNode* node = head;
    
    // push all the nodes on the stack.
    while(node != nullptr) {
      S.push(node);
      node = node->next;
    }
    
    node = head;
    
    // pop em off and merge
    while(node != nullptr) {
      // get pointers to next node and last node
      ListNode* next = node->next;
      ListNode* end = S.top();
      S.pop();
      
      // point next to end, then end to next
      node->next = end;
      end->next = next;
      node = next;
      
      // we are finised when the next node is the same as the end
      if(node != nullptr && node->next == end ) {
        node->next = nullptr;
        break;
      }
    }
  }
};
