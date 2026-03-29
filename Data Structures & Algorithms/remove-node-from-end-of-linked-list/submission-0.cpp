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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int size = 0;
        while (ptr) {
            size++;
            ptr = ptr->next;
        }

        if (size == 1 && n == 1) {
            return nullptr;
        }
        else if (n == size) {
            return head->next;
        }

        ptr = head;
        for (int i = 1; i < (size - n); i++) {
            ptr = ptr->next;
        }
        ptr->next = ptr->next->next;

        return head;
    }
};
