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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        int level = 0;
        int xParentVal = -1;
        int xLevel = -1;
        int yParentVal = -1;
        int yLevel = -1;
        while(!q.empty())
        {
            count = q.size();
            level++;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();

                if(levelNode->left)
                {
                    if(levelNode->left->val == x)
                    {
                        xParentVal = levelNode->val;
                        xLevel = level + 1;
                    }
                    else if(levelNode->left->val == y)
                    {
                        yParentVal = levelNode->val;
                        yLevel = level + 1;
                    }
                    else
                       q.push(levelNode->left); 
                }
                if(levelNode->right)
                {
                    if(levelNode->right->val == x)
                    {
                        xParentVal = levelNode->val;
                        xLevel = level + 1;
                    }
                    else if(levelNode->right->val == y)
                    {
                        yParentVal = levelNode->val;
                        yLevel = level + 1;
                    }
                    else
                       q.push(levelNode->right); 
                }   
            }
            //Nodes have been found
            if(xLevel != -1 && yLevel != -1)
            {
                if(xLevel == yLevel && xParentVal != yParentVal)
                    return true;
                else
                    return false;
            }
        }
        return false;
    }
};