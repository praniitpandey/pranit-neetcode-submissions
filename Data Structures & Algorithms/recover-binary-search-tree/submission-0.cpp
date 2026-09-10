/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        traverse(root);

        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i]->val > arr[i + 1]->val) {
                node2 = arr[i + 1];
                if (!node1) node1 = arr[i];
                else break;
            }
        }

        swap(node1->val, node2->val);
    }
    
private:
    vector<TreeNode*> arr;

    void traverse(TreeNode* root) {
        if (root == nullptr) return;

        traverse(root->left);
        arr.push_back(root);
        traverse(root->right);
    }
};