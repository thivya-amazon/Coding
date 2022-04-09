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
    vector<int> inorder;
    void dfs(TreeNode* node)
    {
        if(!node)
            return;
        dfs(node->left);
        inorder.push_back(node->val);
        dfs(node->right);
    }
    TreeNode* buildBST(int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildBST(start, mid - 1);
        root->right = buildBST(mid + 1, end);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        dfs(root);
        return buildBST(0, inorder.size()-1);
    }
};