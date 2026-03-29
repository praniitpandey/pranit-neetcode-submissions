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
    // Comparator for min-heap
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;  // min-heap
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        ListNode* dummyHead = new ListNode(0);  //to not lose reference to our new LL's head
        ListNode* ptr = dummyHead;  //to create a new LL

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]); //we push all non-empty list heads to minHeap to start
            }
        }

        while (!minHeap.empty()) {
            ListNode* currentSmallest = minHeap.top();

            ptr->next = currentSmallest;    //we add current smallest element to our new LL
            minHeap.pop();

            if (currentSmallest->next != nullptr) {
                minHeap.push(currentSmallest->next);    //if we have not reached the end, we'll push next element to minHeap
            }

            ptr = ptr->next; //advancing pointer for my new LL
        }

        return dummyHead->next; //returning LL after dummyHead
    }
};
