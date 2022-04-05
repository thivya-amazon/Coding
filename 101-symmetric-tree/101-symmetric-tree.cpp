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
    bool dfs(TreeNode* tree1, TreeNode* tree2)
    {
        if(tree1 == NULL && tree2 == NULL)
            return true;
        if(tree1 == NULL || tree2 == NULL)
            return false;
        bool left = false;
        bool right = false;
        if(tree1->val == tree2->val)
        {
            left = dfs(tree1->left, tree2->right);
            right = dfs(tree1->right, tree2->left);
        }
        
        return (left && right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return dfs(root, root);
    }
};