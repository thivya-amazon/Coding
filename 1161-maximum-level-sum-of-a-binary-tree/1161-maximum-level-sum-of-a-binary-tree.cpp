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
    int maxLevelSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        int level = 0;
        int maxSumLevel = 0;
        int maxSum = INT_MIN;
        while(!q.empty())
        {
            count = q.size();
            level++;
            int levelSum = 0;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();
                levelSum += levelNode->val;
                if(levelNode->left)
                    q.push(levelNode->left);
                if(levelNode->right)
                    q.push(levelNode->right);    
            }
            if(levelSum > maxSum)
            {
                maxSum = levelSum;
                maxSumLevel = level;
            }
                
        }
        return maxSumLevel;
    }
};