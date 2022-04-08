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
    TreeNode* closestNode = NULL;
    double minDiff = INT_MAX;
    void dfs(TreeNode* root, double target)
    {
        if(root == NULL)
            return;
        if(root->val == target)
        {
            closestNode = root;
            return;
        }
        if(abs(root->val - target) < minDiff)
        {
            minDiff = abs(root->val - target);
            closestNode = root;
        }
        if(root->val < target)
            dfs(root->right, target);
        else
            dfs(root->left, target);
    }
    int closestValue(TreeNode* root, double target) {
        if(root == NULL)
            return NULL;
        //Round up the target value for comaparison
        // int targetR = ceil(target);
        // if(targetR - target < 0.5)
        //     target = targetR;
        // else
        //     target = floor(target);
        dfs(root, target);
        return closestNode->val;
    }
};