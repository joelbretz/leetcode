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

//PalindromeLinkedList
// naive, easy solution is to reverse the list and just compare.
// should be a 2 pointer solution that uses O(1) space though..

class Solution {
public:
    
    bool checkPalindrome(ListNode** left, ListNode* right) {
        if(!right)
            return true;
        
        bool palindrome = checkPalindrome(left,right->next);
        if((*left)->val != right->val)
            return false;
        //update left before returning
        *left = (*left)->next;
        return palindrome;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *right = head;
        return checkPalindrome(&head,right);
    }
};
