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
    vector<vector<string>> result;
    int getHeight(TreeNode* root)
    {
        if(root == NULL)
            return -1;
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        
        return max(lh, rh) + 1;
    }
    void dfs(TreeNode* node, int row, int col, int height)
    {
        if(node == NULL)
            return;
        result[row][col] = to_string(node->val);
        int col_pos = pow(2, (height-row-1));
        dfs(node->left, row + 1, col - col_pos, height);
        dfs(node->right, row + 1, col + col_pos, height);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == NULL)
            return result;
        int height = getHeight(root);
        int ROWS = height + 1;
        int COLS = pow(2, ROWS)-1;
        result.resize(ROWS, vector<string>(COLS));
        dfs(root, 0, (COLS-1)/2, height);
        return result;
            
    }
};