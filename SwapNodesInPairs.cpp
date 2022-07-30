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
  protected:

  public:
  // two pointers, curr, prev 
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(-1, head); 

    ListNode* prev = dummy;
    ListNode* curr = head;
    while(curr != nullptr && curr->next != nullptr) {
      // setup
      ListNode* a = curr, *b = curr->next;
      // swap
      prev->next = b;
      a->next = b->next;
      b->next = a;
      // reset & move 
      prev = a;
      curr = a->next;
    }
    return dummy->next;
  }
};
