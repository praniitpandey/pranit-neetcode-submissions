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
private:
    int x_max;
    int y_min;
    int y_max;
    unordered_map<int, unordered_map<int, vector<int>>> grid;

    void dfs(TreeNode* root, int x, int y) {
        if (root) {
            grid[x][y].push_back(root->val);

            x_max = max(x, x_max);
            y_min = min(y, y_min);
            y_max = max(y, y_max);

            dfs(root->left, x + 1, y - 1);
            dfs(root->right, x + 1, y + 1);
        }
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        x_max = 0;
        y_min = 0;
        y_max = 0;

        dfs(root, 0, 0);

        vector<vector<int>> ans;
        for (int y = y_min; y <= y_max; y++) {
            ans.push_back(vector<int>());

            for (int x = 0; x <= x_max; x++) {
                if (grid[x].count(y)) {
                    for (int val : grid[x][y])
                        ans.back().push_back(val);
                }
            }
        }

        return ans;
    }
};