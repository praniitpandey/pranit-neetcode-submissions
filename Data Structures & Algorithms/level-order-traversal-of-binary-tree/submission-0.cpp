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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> bfs;
        vector<vector<int>> levels;

        bfs.push(root);
        int currentLevel = 0;

        while (!bfs.empty()) {
            int length = bfs.size();
            levels.push_back({});

            for (int i = 0; i < length; i++) {
                TreeNode* currentNode = bfs.front();
                bfs.pop();
                levels[currentLevel].push_back(currentNode->val);

                if (currentNode->left != nullptr) {
                    bfs.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    bfs.push(currentNode->right);
                }
            }
            ++currentLevel;
        }
        return levels;
    }
};
