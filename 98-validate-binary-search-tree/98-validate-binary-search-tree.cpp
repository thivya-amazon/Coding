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
    bool valid = true;
    bool dfs(TreeNode* root, long maxVal, long minVal)
    {
        if(root == NULL)
            return true;
        bool isBst = false;
        if(root->val < maxVal && root->val > minVal)
        {
            isBst = dfs(root->left, root->val, minVal) && dfs(root->right, maxVal, root->val);
        }
        valid = isBst;
        return isBst;
    }
    bool isValidBST(TreeNode* root) {
       if(root == NULL)
           return valid;
        dfs(root, LONG_MAX, LONG_MIN);
        return valid;
    }
};