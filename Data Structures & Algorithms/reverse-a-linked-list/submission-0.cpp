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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* curr = head, *prev = NULL, *next = NULL;
        while(curr){
            //store next 
            next = curr->next;
            //reverse link
            curr->next = prev;
            //move ahed
            prev = curr;
            curr = next;
        }
        return prev;
        
        
    }
};
