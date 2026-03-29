/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* ptr = headA;
        long long lengthA = 0;
        while (ptr) {
            ptr = ptr->next;
            ++lengthA;
        }
        ptr = headB;
        long long lengthB = 0;
        while (ptr) {
            ptr = ptr->next;
            ++lengthB;
        }

        long long diff = abs(lengthA - lengthB);
        if (lengthA > lengthB) {
            for (long long i = 0; i < diff; i++) {
                headA = headA->next;
            }
        }
        else if (lengthB > lengthA) {
            for (long long i = 0; i < diff; i++) {
                headB = headB->next;
            }
        }

        while (headA && headB) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};