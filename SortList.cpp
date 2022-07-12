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
  void printList(ListNode* head) {
    cout << "["; 
    ListNode *curr = head;
    while(curr) {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout <<"]" << endl; 
  }
  // mergesort utility to split list into 2 halves
  void split(ListNode* head, ListNode** l1, ListNode** l2) {
    // split the list in halves using slow/fast pointers
    ListNode *slow = head, *fast = head->next; 
    
    while(fast) { 
      fast = fast->next;

      if(fast) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *l1 = head;
    *l2 = slow->next;
    slow->next = nullptr;
  }  

  // merge sort utility that does the work of merging the list(s)
  ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode *merged = nullptr;
    
    // base cases
    if(!l1)
      return l2;
    else if(!l2)
      return l1;

    // choose next node
    if(l1->val <= l2->val) {
      merged = l1;
      merged->next = merge(l1->next, l2);
    }
    else {
      merged = l2;
      merged->next = merge(l1, l2->next);
    }
    return merged;
  }
  
  void mergeSort(ListNode** p) {
    ListNode *head = *p;
    ListNode *left, *right;

    if(!head || !head->next)
      return ;

    split(head,&left,&right);

    // merge sort
    mergeSort(&left);
    mergeSort(&right);

    *p = merge(left,right); 
  }

  // d. mergesort
  ListNode* sortList(ListNode* head) {
    mergeSort(&head);
    return head;
  }

  // c. quick sort
  //    i don't remember this.  i will come back
  ListNode* quickSortList(ListNode* head) {
    if(!head)
      return nullptr;
    
    return head;
  }
  // b. Selection sort
  // O(n^2) worst case, O(n) best case. expect marginal
  // improvement over bubble sort
  // - expect TLE for long(er/est) test cases.
  ListNode* selectionSortList(ListNode* head) {
    if(!head)
      return nullptr;

    ListNode* trailingNode = head;
    ListNode* leadingNode = nullptr;
    ListNode* smallestNode = nullptr;

    while(trailingNode) {
      smallestNode = trailingNode;
      leadingNode = trailingNode->next;
      while(leadingNode) {
        //cout << "compare: " << trailingNode->val << " " << leadingNode->val << endl;
        if(leadingNode->val < trailingNode->val) {
          //cout << "  leading val < trailing val: check smallest" << endl;
          if(leadingNode->val < smallestNode->val) {
            //cout <<"  update currSmallest: " << leadingNode->val << endl;
            smallestNode = leadingNode;
          }
        }
        leadingNode = leadingNode->next;
      }
      swap(trailingNode->val, smallestNode->val);
      trailingNode = trailingNode->next;
    }  
    return head;
  }

  // a. bubble sort O(n^2), iterative. O(1) space
  // - expect TLE for long(er/est) test cases.
  ListNode* bubbleSortList(ListNode* head) {
    if(!head)
      return nullptr;
    ListNode *newHead = head;
    ListNode* trailingNode = head;
    ListNode* leadingNode = head;

    while(trailingNode) { 
      leadingNode = trailingNode->next;
      while(leadingNode != nullptr) {
        //cout << "comparing: " << trailingNode->val << " " << leadingNode->val << endl;
        if(leadingNode->val < trailingNode->val) {
          swap(leadingNode->val, trailingNode->val);
        }
        leadingNode = leadingNode->next;
      }
      trailingNode = trailingNode->next;
    }
    return head;

  }
};
