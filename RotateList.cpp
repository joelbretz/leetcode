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
  ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr || head->next == nullptr)
      return head;
    
    // find the tail and make it a circle, count nodes
    ListNode *tail = head;
    int n = 1;
    for(;tail->next != nullptr; ++n) 
      tail = tail->next;
    tail->next = head;
    
    // find the new tail node by counting
    // tail is the n - k % n - 1 th node
    ListNode *rotatedTail = head;
    for(int i = 0; i < (n - k % n - 1); ++i)
      rotatedTail = rotatedTail->next;
    ListNode* rotatedHead = rotatedTail->next;
    
    // break cirle
    rotatedTail->next = nullptr;
    
    return rotatedHead;
  }
};
