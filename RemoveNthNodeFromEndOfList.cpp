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
  // Single Pass, O(n) time, O(n) space from to store nodes.
  // 3 cases: n==k, delete first. k==1, delete last
  // k < n 
  ListNode* removeNthFromEnd(ListNode* head, int k) {
    
    vector<ListNode*> nodes;
    ListNode* curr = head;
    // copy nodes to vector
    while(curr) {
      nodes.push_back(curr);
      curr = curr->next;
    }
    // remove node n-k
    int n = nodes.size();
    if(n == k) // delete first
      return head->next;
   else if(k==1) // delete last
      nodes[n-2]->next = nullptr;
    else
      nodes[n-k-1]->next = nodes[n-k+1];
      
    return head;
  }
};
