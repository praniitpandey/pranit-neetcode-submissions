class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* groupLast = groupPrev;

            for (int i = 0; i < k && groupLast != nullptr; i++) {
                groupLast = groupLast->next;
            }

            if (groupLast == nullptr) {
                break;
            }

            ListNode* groupNext = groupLast->next;
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            for (int i = 0; i < k; i++) {
                ListNode* temp = curr->next;
                curr->next = prev;

                prev = curr;
                curr = temp;
            }

            ListNode* nextGroupPrev = groupPrev->next;
            groupPrev->next = groupLast;
            groupPrev = nextGroupPrev;
        }

        return dummy->next;
    }
};