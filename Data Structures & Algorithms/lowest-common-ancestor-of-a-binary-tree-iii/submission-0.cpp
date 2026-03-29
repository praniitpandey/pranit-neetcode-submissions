/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> path1;

        while (p != nullptr) {
            path1.insert(p);
            p = p->parent;
        }

        while (q != nullptr) {
            if (path1.count(q)) {
                return q;
            }
            q = q->parent;
        }

        return nullptr;
    }
};