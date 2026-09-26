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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;

        ListNode* dummy = new ListNode();
        ListNode* tmp1= l1;
        ListNode* tmp2 = l2;
        ListNode* tmp3 = dummy;

        while(carry || tmp1 || tmp2){
            int curr = carry;
            if(tmp1){
                curr += tmp1->val;
                tmp1 = tmp1->next;
            }
            if(tmp2){
                curr +=tmp2->val;
                tmp2 = tmp2->next;
            }
            
            tmp3->next = new ListNode(curr%10);
            tmp3= tmp3->next;
            carry = curr/10;    
        }
        return dummy->next;
        
    }
};
