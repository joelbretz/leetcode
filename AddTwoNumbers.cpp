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
    // return a completely new ListNode, Iterative
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* dummy = new ListNode(-1);
      ListNode* curr = dummy;
      int carry = 0;
      while(l1 || l2 || carry) {
        int u = l1 ? l1->val : 0;
        int v = l2 ? l2->val : 0;
        int t = u + v + carry;
        carry = t / 10;
        curr->next = new ListNode(t % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
      }
      return dummy->next;
    }
    // inplace iterative, doesn't handle p2.length != p1.length
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
     
      ListNode *p1 = l1, *p2 = l2; 
      while(p1 && p2) {
        p1->val += p2->val;
        if(p1->val >= 10) {
          p1->val -= 10;
          p1->next->val += 1;
        }
        p1 = p1->next; p2 = p2->next;
      }
      return l1;
    }
};
