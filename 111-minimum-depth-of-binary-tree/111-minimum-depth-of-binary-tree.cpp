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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        int level = 0;
        int minDepth = INT_MAX;
        while(!q.empty())
        {
            count = q.size();
            level++;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();
                if(levelNode->left == NULL && levelNode->right == NULL)
                    minDepth = min(minDepth, level);
                else
                {
                    if(levelNode->left)
                        q.push(levelNode->left);
                    if(levelNode->right)
                        q.push(levelNode->right);
                }
                
            }
        }
        return minDepth;
    }
};