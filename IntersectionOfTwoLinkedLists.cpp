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
  
  // fancier solution keep iterating until they're the same.
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
   ListNode *pA = headA; ListNode *pB = headB;
    while(pA != pB) {
      if(pA == nullptr)
        pA = headB;
      else
        pA = pA->next;
      
      if(pB == nullptr)
        pB = headA;
      else
        pB = pB->next;
    }
    return pA;
  }
  
  // Two pointers O(n+m) time O(1) space,  consecutive loops
  ListNode *getIntersectionNodev2(ListNode *headA, ListNode *headB) {
    int lenA = 0; int lenB = 0;
    ListNode *pA = headA; ListNode *pB = headB;
    //1st loop finds length of shorter list
    while(pA && pB) {
      lenA++; lenB++;
      pA = pA->next; pB = pB->next;
    }
    
    // 2nd loop finds length of longer list;
    while(pA) {
      lenA++;
      pA = pA->next;
    }
    while(pB) {
      lenB++;
      pB = pB->next;
    }
    // reset pointers and advance the pointer to
    // the longer list by abs(lenB-lenA)
    pA = headA; pB = headB;
    if(lenA > lenB) {
      int n = lenA - lenB;
      while(n--)
        pA = pA->next;
    }
    else if(lenB > lenA) {
      int n = lenB - lenA;
      while(n--)
        pB = pB->next;
    }
    
    // now just step through until they're the same;
    while(pA && pB) {
      if(pA == pB)
        return pA;
      pA = pA->next;
      pB = pB->next;
    }
    
    return nullptr;
  }
  // hash table solution: O(n+m) time, O(m) space
  // iterate over a add to hash. 
  // then iterate over b, return when we find something already 
  // in the hash.
  ListNode *getIntersectionNodeHash(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode*> nodes;
    ListNode *pA = headA;
    while(pA != nullptr) {
      nodes.insert(pA);
      pA = pA->next;
    }
    ListNode *pB = headB;
    while(pB != nullptr) {
      if(nodes.insert(pB).second == false)
        return pB;
      pB = pB->next; 
    }
    return pB;
  }
};
