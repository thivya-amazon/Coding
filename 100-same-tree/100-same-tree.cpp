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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty())
        {
            TreeNode* pLevelNode = q1.front(); q1.pop();
            TreeNode* qLevelNode = q2.front(); q2.pop();
            if(pLevelNode->val != qLevelNode->val)
                return false;
            if((pLevelNode->left && !qLevelNode->left) || (!pLevelNode->left && qLevelNode->left))
                return false;
            if((pLevelNode->right && !qLevelNode->right) || (!pLevelNode->right && qLevelNode->right))
                return false;
            if(pLevelNode->left && qLevelNode->left)
               {
                   q1.push(pLevelNode->left);
                   q2.push(qLevelNode->left);
               }
            if(pLevelNode->right && qLevelNode->right)
               {
                   q1.push(pLevelNode->right);
                   q2.push(qLevelNode->right);
               }
            
        }
        return true;
        
    }
};