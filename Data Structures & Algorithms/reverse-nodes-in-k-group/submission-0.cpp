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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* tmp = head;

        for(int i=0;i<k;i++){
            if(!tmp) return head;
            tmp=tmp->next;
        }

        //reverse
        tmp = head;
        ListNode *prev, *next, *curr = head;
        int cnt = 0;
        while(cnt<k){
            //store next
            next =curr->next;
            //reverse
            curr->next = prev;
            //step forward
            prev = curr;
            curr = next;
            cnt++;
        }

        head->next = reverseKGroup(curr,k);
        return prev;
        
    }
};
