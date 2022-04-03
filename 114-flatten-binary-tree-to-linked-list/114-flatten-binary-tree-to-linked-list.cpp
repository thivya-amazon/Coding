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
    TreeNode* dfs(TreeNode* node, TreeNode* pred)
    {
        TreeNode* oldLeft = NULL;
        TreeNode* oldRight = NULL;
        if(node->left)
            oldLeft = node->left;
        if(node->right)
            oldRight = node->right;
        //Link the pred to the node
        pred->right = node;
        pred->left = NULL;
        pred = node;
        if(oldLeft)
            pred = dfs(oldLeft, pred);
        if(oldRight)
            pred = dfs(oldRight, pred);
        
        return pred;
    }
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* sentinel = new TreeNode(INT_MIN);
        dfs(root, sentinel);
    }
};