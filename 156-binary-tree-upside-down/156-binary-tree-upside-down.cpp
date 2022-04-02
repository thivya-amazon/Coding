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
    void dfs(TreeNode* root, TreeNode* parent, TreeNode* rightSibling)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
            newRoot = root;
        
        TreeNode* oldLeft = root->left;
        TreeNode* oldRight = root->right;
        root->left = rightSibling;
        root->right = parent;
        
        dfs(oldLeft, root, oldRight);
        
    }
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
      if(root == NULL)
          return NULL;
        dfs(root, NULL, NULL);
        return newRoot;
    }
};