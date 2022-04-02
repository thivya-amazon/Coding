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
/*
Global problem - longest univalue path in the tree
Local problem - longest univalue path through me in my subtree
*/
class Solution {
public:
    int maxPathLen = 0;
    int dfs(TreeNode* root)
    {
                
        int left = 0;
        int right = 0;
        int leftUnivalPath = 0;
        int rightUnivalPath  = 0;
        int myUnivalPath = 0;

        if(root->left)
        {
            left = dfs(root->left);
            if(root->val == root->left->val)
                leftUnivalPath = left + 1;
        }
            
        if(root->right)
        {
            right = dfs(root->right);
            if(root->val == root->right->val)
                rightUnivalPath =right + 1;
        }
       myUnivalPath = max(leftUnivalPath, rightUnivalPath);
       maxPathLen = max(maxPathLen, leftUnivalPath+rightUnivalPath); 
        
        return(myUnivalPath);
            
    }
    int longestUnivaluePath(TreeNode* root) {
      if(root == NULL)
          return 0;
      dfs(root);  
        return maxPathLen;
    }
};