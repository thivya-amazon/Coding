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
    int diameter = 0;
    int getDiameter(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return 0;
        int lh = 0;
        int rh = 0;
        int height = 0;
        if(root -> left)
        {
            lh = getDiameter(root->left) + 1;
            height =  max(height, lh);
        }
            
        if(root -> right)
        {
            rh = getDiameter(root->right) + 1;
            height = max(height, rh);
        }
            
        diameter = max(diameter, lh+rh);
        return height;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        getDiameter(root);
        return diameter;
    }
};