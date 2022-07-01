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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = head;
    ListNode* prev = dummy;
   
    if(!head)
      return nullptr;
    
    ListNode* curr = dummy->next;

    while(curr) {
      //cout << "compare: " << prev->val << "," << curr->val << endl;
      if(prev->val == curr->val) { 
        curr = curr->next;
        prev->next = curr;    
      }
      else {
        curr = curr->next;
        prev = prev->next;
      }
    }
    return dummy;
  }
};
