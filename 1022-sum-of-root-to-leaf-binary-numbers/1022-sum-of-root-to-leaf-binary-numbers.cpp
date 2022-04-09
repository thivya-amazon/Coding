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
    int sum = 0;
    void dfs(TreeNode* node, int currNum)
    {
        if(!node)
            return;
        currNum = (currNum << 1) | node->val;
        if(node->left == NULL && node->right == NULL)
            sum += currNum;
        dfs(node->left, currNum);
        dfs(node->right, currNum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root, 0);
        return sum;
        
    }
};