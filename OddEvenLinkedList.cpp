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
  // single pass, copies nodes into even list and odd
  // list then concats them
  ListNode* oddEvenList(ListNode* head) {
    
    if(!head)  // no nodes
      return nullptr;
   
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while(even != nullptr && even->next != nullptr) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    odd->next = evenHead;
    return head;
  }
};
