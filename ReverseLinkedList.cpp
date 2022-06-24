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
  // novel iterative solution
  ListNode* reverseListI(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while(curr) {
      ListNode* temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
  }

  // classic recursive, 2nd year CS solution.
  ListNode* reverseListR(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
  }
};
