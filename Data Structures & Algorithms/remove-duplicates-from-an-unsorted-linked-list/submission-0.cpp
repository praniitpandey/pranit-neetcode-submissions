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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* ptr = head;
        unordered_map<int, int> freq;

        while (ptr) {
            ++freq[ptr->val];
            ptr = ptr->next;
        }

        ListNode* dummy = new ListNode(-1, head);
        ptr = dummy;

        while (ptr->next) {
            if (freq[ptr->next->val] > 1) {
                ptr->next = ptr->next->next;
            } 
            else {
                ptr = ptr->next;
            }
        }

        return dummy->next;
    }
};