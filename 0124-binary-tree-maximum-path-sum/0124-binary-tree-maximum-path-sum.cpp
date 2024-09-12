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
    int findMaxSum(TreeNode* root, int &maxi){
        if(root == NULL) return 0;
        
        int leftMaxPath = max(0, findMaxSum(root->left, maxi));
        int rightMaxPath = max(0, findMaxSum(root->right, maxi));
        
        maxi = max(maxi, (leftMaxPath + rightMaxPath + root->val));
            return root->val + max(leftMaxPath, rightMaxPath);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        
        findMaxSum(root,maxi);
        return maxi;
    }
};