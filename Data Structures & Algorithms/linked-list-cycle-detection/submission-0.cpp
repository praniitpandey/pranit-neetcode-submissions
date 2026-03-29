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
    bool hasCycle(ListNode* head) {
        ListNode* it = head;
        unordered_set<ListNode*> visited_nodes;

        while(it) {
            if (visited_nodes.find(it) == visited_nodes.end()) {
                visited_nodes.insert(it);
            }
            else {
                return true;
            }
            it = it->next;
        }

        return false;
    }
};
