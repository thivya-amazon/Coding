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
    void dfs(TreeNode* root, int curr)
    {
        if(root == NULL)
            return;
        curr = curr*10 + root->val;
       
        if(root->left == NULL && root->right == NULL)
        {
            sum += curr;
            //cout << "sum = " << sum << endl;
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
       
        dfs(root, 0);
        return sum;        
    }
};