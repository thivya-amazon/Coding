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
    int maxSum = INT_MIN;
    int dfs(TreeNode* node)
    {
        int myMaxPathSum = node->val;
        int myMaxVPathSum = node->val;
        int leftSum = 0;
        int rightSum = 0;
                
        if(node->left)
        {
            leftSum = dfs(node->left);
            myMaxPathSum = max(myMaxPathSum, node->val + leftSum);
            myMaxVPathSum = myMaxPathSum;
        }
        if(node->right)
        {
            rightSum = dfs(node->right);
            myMaxPathSum = max(myMaxPathSum, rightSum + node->val);
            myMaxVPathSum = max(myMaxVPathSum, max(rightSum + node->val, myMaxVPathSum + rightSum));
        }

        maxSum = max(maxSum, myMaxVPathSum);
        return myMaxPathSum;       
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return maxSum;
    }
};