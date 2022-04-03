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
    int globalTilt = 0;
    int dfs(TreeNode* node)
    {
        if(node->left == NULL && node->right == NULL)
            return node->val;
        int myTilt = 0;
        int leftSubVal = 0;
        int rightSubVal = 0;
        int sum = 0;
        if(node->left)
        {
            leftSubVal = dfs(node->left);
        }
        if(node->right)
        {
            rightSubVal = dfs(node->right);
        }
        sum = node->val + leftSubVal + rightSubVal;
        myTilt = abs(leftSubVal - rightSubVal);
        globalTilt += myTilt;
        return sum;
            
    }
    int findTilt(TreeNode* root) {
      if(root == NULL)
          return 0;
        dfs(root);
        return globalTilt;
    }
};