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
    void dfs(TreeNode* root)
    {
        if(root == NULL)
            return;
        //Internal nodes
        TreeNode* oldLeft = root->left;
        TreeNode* oldRight = root->right;
        root->left = oldRight;
        root->right = oldLeft;
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        dfs(root);
        return root;
    }
};