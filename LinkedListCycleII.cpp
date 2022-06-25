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
  // trivial solution, use a set. detect
  // when we get a node we've already seen.
  ListNode *detectCycleTrivial(ListNode *head) {
    unordered_set<ListNode*> nodeSet;
    while(head != nullptr) {
      auto it = nodeSet.insert(head);
      if(it.second == false)
        return *it.first;
      head = head->next;
    }
    return nullptr;
  }
  
  
  // Either finds where slow == fast or 
  // returns nullptr
  ListNode* getIntersection(ListNode* head) {
    ListNode* tortoise = head;
    ListNode* hare = head;
    while(hare && hare->next) {
      tortoise = tortoise->next;
      hare = (hare->next)->next;
      if(tortoise == hare)
        return tortoise;
    }
    return nullptr;
  }
  // Use Floyd's tortoise and hare.
  // 
  ListNode *detectCycle(ListNode *head) {
    if(!head)
      return nullptr;
    
    // Phase 1: Find intersection.
    ListNode* intersect = getIntersection(head);
    if(intersect == nullptr)
      return nullptr;
    
    // Phase 2: find entrance to cycle
    ListNode* ptr1 = head;
    ListNode* ptr2 = intersect;
    while(ptr1 != ptr2) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
    }
    return ptr1;
  }
};
