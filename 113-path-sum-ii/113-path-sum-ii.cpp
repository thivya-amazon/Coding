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
     vector<vector<int>> result;
    void dfs(TreeNode* root, vector<int>& slate, int target)
    {
        if(root == NULL)
            return;
        slate.push_back(root->val);
        target = target - root->val;
        if(root->left == NULL && root->right == NULL)
        {
            if(0 == target)
                result.push_back(slate);
        }
        dfs(root->left, slate, target);
        dfs(root->right, slate, target);
        slate.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return result;
        vector<int> slate;
        dfs(root, slate, targetSum);
        return result;
    }
};