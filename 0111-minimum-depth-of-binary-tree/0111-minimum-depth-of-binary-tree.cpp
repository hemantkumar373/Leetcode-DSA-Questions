/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        int lh = root->left ? minDepth(root->left) : INT_MAX;
        int rh = root->right ? minDepth(root->right) : INT_MAX;

        return 1 + min(lh, rh);
    }
};