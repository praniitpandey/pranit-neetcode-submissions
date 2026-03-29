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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* ptr = head;
        stack<ListNode*> st;

        while (ptr) {
            st.push(ptr);
            ptr = ptr->next;
        }

        ListNode* dummyHead = new ListNode(0);
        ptr = dummyHead;
        while (!st.empty()) {
            ptr->next = st.top();
            st.pop();
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        
        return dummyHead->next;
    }
};