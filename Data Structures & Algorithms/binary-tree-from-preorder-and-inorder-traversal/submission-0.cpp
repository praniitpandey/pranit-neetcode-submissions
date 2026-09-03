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
    unordered_map<int, int> index;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        reverse(preorder.begin(), preorder.end());

        for (int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;

        return buildTree(0, inorder.size() - 1, inorder, preorder);
    }

    TreeNode* buildTree(int left, int right, vector<int>& inorder, vector<int>& preorder) {
        if (left > right)
            return nullptr;


        int rootIndex = index[preorder.back()];
        preorder.pop_back();

        TreeNode* rootNode = new TreeNode(inorder[rootIndex]);

        rootNode->left = buildTree(left, rootIndex - 1, inorder, preorder);
        rootNode->right = buildTree(rootIndex + 1, right, inorder, preorder);

        return rootNode;
    }
};
