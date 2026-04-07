class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }

            if (kth == nullptr) {
                break;
            }

            ListNode* groupNext = kth->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            ListNode* nextGroupPrev = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = nextGroupPrev;
        }

        return dummy->next;
    }
};