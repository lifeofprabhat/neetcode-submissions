/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* tmp = head;
        Node* dummy = new Node(0);
        Node* head1= dummy;
        while(tmp){
            Node* curr = new Node(tmp->val);
            mp[tmp] = curr;
            dummy->next = curr;
            dummy = curr;
            tmp = tmp->next;

        }

        Node* tmp1 = head1->next;
        tmp = head;
        while(tmp){
            tmp1->random = mp[tmp->random];
            tmp= tmp->next;
            tmp1= tmp1->next;

        }

        return head1->next;
        
    }
};
