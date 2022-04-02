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
    int maxPathLen = 0;
    int dfs(TreeNode* root)
    {
                
        int left = 0;
        int right = 0;
        int leftArrows = 0;
        int rightArrows  = 0;
        int arrowPath = 0;

        if(root->left)
        {
            left = dfs(root->left);
            if(root->val == root->left->val)
                leftArrows = left + 1;
        }
            
        if(root->right)
        {
            right = dfs(root->right);
            if(root->val == root->right->val)
                rightArrows =right + 1;
        }
        arrowPath = max(leftArrows, rightArrows);
       maxPathLen = max(maxPathLen, leftArrows+rightArrows); 
        
        return(arrowPath);
            
    }
    int longestUnivaluePath(TreeNode* root) {
      if(root == NULL)
          return 0;
      dfs(root);  
        return maxPathLen;
    }
};