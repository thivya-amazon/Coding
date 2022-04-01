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
    int value = 0;
    int leftMostVal = 0;
    int maxLevel = -1;
    void dfs(TreeNode* root, int level)
    {
        if(root == NULL)
            return;
        if(level > maxLevel)
        {
            leftMostVal = root->val;
            maxLevel = level;
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        dfs(root, 0);
        return leftMostVal;
    }
};