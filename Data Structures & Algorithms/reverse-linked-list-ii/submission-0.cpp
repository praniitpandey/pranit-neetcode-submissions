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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* leftptr = dummy;

        for (int i = 1; i < left && leftptr; i++) {
            leftptr = leftptr->next;
        }

        ListNode* rightptr = leftptr->next;

        for (int i = left; i <= right && rightptr; i++) {
            rightptr = rightptr->next;
        }

        ListNode* prev = rightptr;
        ListNode* curr = leftptr->next; 
        ListNode* temp;

        while (curr && curr != rightptr) {
            temp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = temp;
        }
        
        leftptr->next = prev;

        return dummy->next;        
    }
};