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
    bool path = false;
    void dfs(TreeNode* node, int target)
    {
        if(node == NULL)
            return;
        target = target - node->val;
        if(node->left == NULL && node->right == NULL)
        {
            if (target == 0)
                path = true;                
        }
        dfs(node->left, target);
        dfs(node->right, target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return path;
        dfs(root, targetSum);
        return path;
    }
};