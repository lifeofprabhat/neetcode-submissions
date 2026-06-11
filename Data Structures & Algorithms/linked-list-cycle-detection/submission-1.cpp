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
    bool hasCycle(ListNode* head) {
        
        if(!head || !head->next) return 0;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(1){
           if(slow == fast) return 1;

           if(!fast || !fast->next || !fast->next->next)
            return 0;

            slow = slow->next;
            fast = fast->next->next;
        }
        return 0;
        
    }
};
