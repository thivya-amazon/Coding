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
    bool balanced = true;
    int dfs(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            
        }
        int leftHeight = 0;
        int rightHeight = 0;
        int myHeight = 0;
        if(root->left)
        {
            leftHeight = dfs(root->left) + 1;
        }
        if(root->right)
        {
            rightHeight = dfs(root->right) + 1;
        }
        if(abs(leftHeight - rightHeight) > 1)
            balanced = false;
        myHeight = max(leftHeight, rightHeight);
        return myHeight;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        dfs(root);
        return balanced;
            
    }
};