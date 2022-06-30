/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
  // use a two pointer approach
  // they'll catch up if it's cyclical.
  // the start of this cycle can be found easily too.
  // O(n) time, O(1) space
  bool hasCycle(ListNode *head) {
    if(!head)
      return false;

    ListNode* tortoise = head;
    ListNode* hare = head->next;
    while(tortoise != hare) {
      if(hare == nullptr || hare->next == nullptr) 
        return false;
      tortoise = tortoise->next;
      hare = hare->next->next;
    }
    return true;
  }
  
  
  // use set to store nodes. bail if 
  // i try to insert a node again.
  // O(n) time, O(n) space
  bool hasCycleSet(ListNode *head) {
    unordered_set<ListNode*> nodes;
    ListNode *curr = head;
    while(curr != nullptr) {
      auto it = nodes.insert(curr);
      if(it.second == false)
        return true;
      curr = curr->next;
    }
    return false;
  }
};
