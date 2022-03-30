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
     
    void dfs(TreeNode* root, vector<int>& slate)
    {
        slate.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            string path; 
            for(int i = 0; i < slate.size(); i++)
            {
                path += to_string(slate[i]);
                if(i != slate.size()-1)
                    path += "->";
            }
            result.push_back(path);
        }
        if(root->left)
            dfs(root->left, slate);
        if(root->right)
            dfs(root->right, slate);
         slate.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL)
            return result;
        vector<int> slate;
        dfs(root, slate);
        return result;
    }
};