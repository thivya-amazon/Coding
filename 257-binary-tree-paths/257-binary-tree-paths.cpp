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
    vector<string> result;
     
    void dfs(TreeNode* root, string slate)
    {
        if(root == NULL)
            return;
        slate += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
            result.push_back(slate);
        else
        {
            slate += "->";
            dfs(root->left, slate);
            dfs(root->right, slate);
        }
            
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return result;
        string slate;
        dfs(root, slate);
        return result;
    }
};