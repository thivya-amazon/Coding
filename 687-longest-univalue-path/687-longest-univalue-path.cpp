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
        if(root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        int leftArrows = 0;
        int rightArrows = 0;
        if(root->left && root->val == root->left->val)
            leftArrows = left+1;
        if(root->right && root->val == root->right->val)
            rightArrows = right+1;
       maxPathLen = max(maxPathLen, leftArrows+rightArrows); 
        
        return(max(rightArrows, leftArrows));
            
    }
    int longestUnivaluePath(TreeNode* root) {
      if(root == NULL)
          return 0;
      dfs(root);  
        return maxPathLen;
    }
};