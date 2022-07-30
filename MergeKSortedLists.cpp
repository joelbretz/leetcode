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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0)
      return nullptr;
    
    ListNode* dummy = new ListNode();
    ListNode* merged = dummy;
    const int numLists = lists.size();
    vector<bool> finished(numLists, false);
    
    // continue adding until all values of finished are true/
    while(find(finished.begin(), finished.end(), false) != finished.end()) {
      pair<int,int> currMin = {INT_MAX, 0}; // min_value, 
      for(int i = 0; i < numLists; ++i) {
        if(finished[i]) {
          //cout << " already finished[" << i << "]"  << endl; 
          continue;
        }
        else if(lists[i] == nullptr) {
          //cout << " setting finished[" << i << "] = true"  << endl; 
          finished[i] = true;
          continue;
        }
        else if(lists[i]->val < currMin.first) {
          //cout << "  updating currmin =  " << lists[i]->val << ", from list " << i << endl;
          currMin = {lists[i]->val, i};
        }  
      }
      if(currMin.first != INT_MAX) {
        //cout << " adding " << currMin.first << " to merged" << endl;
        merged->next = new ListNode(currMin.first);
        merged = merged->next;
        lists[currMin.second] = lists[currMin.second]->next;
      }
    }
      
    
    return dummy->next;

  }
};
