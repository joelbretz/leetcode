/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*It is guaranteed that the node to be deleted is not a tail node in the list.*/

class Solution {
  protected:
  public:
  void deleteNode(ListNode* node) {
    ListNode* tmp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete tmp;
  }
};
