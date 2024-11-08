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
class NodeValue{
    public:
    int maxNode, minNode, sum;
    
    NodeValue(int maxNode, int minNode, int sum){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
    }
};
class Solution {
private:
    int maxSum = 0;
    NodeValue bstHelper(TreeNode *root){
        if(!root) return NodeValue(INT_MIN, INT_MAX, 0);
        
        auto left = bstHelper(root->left);
        auto right = bstHelper(root->right);
        
        if(left.maxNode < root->val && right.minNode > root->val){
            int currSum = left.sum + right.sum + root->val;
            
            maxSum = max(maxSum, currSum);
            
            return NodeValue(max(root->val, right.maxNode),
                   min(root->val, left.minNode), currSum);
        }
        
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
public:
    int maxSumBST(TreeNode* root) {
        bstHelper(root);
        return maxSum > 0 ? maxSum : 0;
    }
};