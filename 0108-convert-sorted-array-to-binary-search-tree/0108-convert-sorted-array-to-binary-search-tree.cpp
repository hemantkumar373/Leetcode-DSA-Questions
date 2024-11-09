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
    TreeNode* bst(vector<int> &nums, int low, int high){
        if(low > high) return NULL;
        int mid = (low + high) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = bst(nums, low, mid-1);
        node->right = bst(nums, mid+1, high);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return bst(nums, 0, nums.size()-1);
    }
};