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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> rightSide;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int currentLevelLength = bfs.size();

            for (int i = 0; i < currentLevelLength; i++) {
                TreeNode* currentNode = bfs.front();
                bfs.pop();

                if (i == currentLevelLength - 1) {
                    rightSide.push_back(currentNode->val);
                }

                if (currentNode->left) {
                    bfs.push(currentNode->left);
                }
                if (currentNode->right) {
                    bfs.push(currentNode->right);
                }
            }
        }

        return rightSide;        
    }
};
