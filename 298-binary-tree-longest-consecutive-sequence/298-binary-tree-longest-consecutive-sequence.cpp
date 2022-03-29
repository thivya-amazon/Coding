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
    int maxLength = 0;
    void dfs(TreeNode* child, TreeNode* parent, int length)
    {
        if(child == NULL)
            return;
        length = (parent != NULL && parent->val+1 == child->val) ? length+1 : 1;
        maxLength = max(maxLength, length);
        dfs(child->left, child, length);
        dfs(child->right, child, length);
    }
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)
            return 0;
        dfs(root, NULL, 0);
        return maxLength;        
    }
};