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
    int count = 0;
    bool dfs(TreeNode* root)
    {
         bool isUnival = true;
        //Leaf nodes
        if(root->left == NULL && root->right == NULL)
        {
            count++;
            return true;
        }
        
        //Internal nodes
        if(root->left)
        {
            bool left = dfs(root->left);
            if(!left || root->val != root->left->val)
                isUnival = false;
            
        }
        if(root->right)
        {
            bool right = dfs(root->right);
            if(!right || root->val != root->right->val)
                isUnival = false;            
        }
        if(isUnival)
            count++;
        return isUnival;
    }
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return count;
    }
};