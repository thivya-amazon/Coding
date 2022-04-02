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
    TreeNode* newRoot = NULL;
    TreeNode* dfs(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL)
        {
            newRoot = root;
            return root;
        }
        TreeNode* newParent = dfs(root->left);
        newParent->right = root;
        newParent->left = root->right;
        root->left = NULL;
        root->right = NULL;
        
        return root;
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL)
            return root;
        dfs(root);
        return newRoot;
    }
};