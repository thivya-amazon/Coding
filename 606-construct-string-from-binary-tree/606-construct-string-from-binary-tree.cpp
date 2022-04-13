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
   
    string dfs(TreeNode* root) {
        string result = "";
        if(!root)
            return "";
        result += to_string(root->val);
        if(root->left || root->right)
        {
            result.append("(");
            result.append(dfs(root->left));
            result.append(")");
        }
        if(root->right)
        {
            result.append("(");
            result.append(dfs(root->right));
            result.append(")");
        }
        return result;
    }
    string tree2str(TreeNode* root) {
        if(!root)
            return "";
        return dfs(root);
    }
};