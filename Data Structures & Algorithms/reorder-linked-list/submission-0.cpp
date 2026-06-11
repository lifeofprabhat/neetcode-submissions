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
    ListNode* getSecondHalf(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ret = slow->next;
        slow->next = NULL;
        return ret;
    }

    ListNode* ReverseSecondHalf(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* mergeList(ListNode* first, ListNode* second, int turn){
        if(!first) return second;
        if(!second) return first;

        if(!turn) {
            first->next = mergeList(first->next,second, 1);
            cout<<first->val<<" ";
            return first;
        }

        second->next = mergeList(first, second->next, 0);
        cout<<second->val<<" ";
        return second;
    }
    void Print(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* secondHalf = getSecondHalf(head);
        Print(head);

        
        ListNode* rSecondHalf = ReverseSecondHalf(secondHalf);
        Print(rSecondHalf); 
        ListNode* final1 = mergeList(head, rSecondHalf,0);
        head = final1;
        return ;
        
    }
};
