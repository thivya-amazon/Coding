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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        stack<int> s;
       
        int level = -1;
        q.push(root);
        while(!q.empty())
        {
            vector<int> slate;
            int count = q.size();
            level++;
            for(int i = 0 ; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();
                if(level % 2 == 0)
                    slate.push_back(levelNode->val);
                else
                    s.push(levelNode->val);
                if(levelNode->left)
                    q.push(levelNode->left);
                if(levelNode->right)
                    q.push(levelNode->right);
            }
            if(level % 2 == 0)
                result.push_back(slate);
            else
            {
                while(!s.empty())
                {
                    slate.push_back(s.top());
                    s.pop();
                }
                result.push_back(slate);
            }
        }
        return result;
    }

};