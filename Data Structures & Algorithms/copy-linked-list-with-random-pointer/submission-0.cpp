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
        Node* ptr1 = head;
        Node* dummy = new Node(0);
        Node* ptr2 = dummy;

        unordered_map<Node*,Node*> map;

        while (ptr1) {
            ptr2->next = new Node(ptr1->val);
            map[ptr1] = ptr2->next;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        ptr1 = head;
        ptr2 = dummy->next;

        while (ptr1) {
            ptr2->random = map[ptr1->random];

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return dummy->next;        
    }
};
