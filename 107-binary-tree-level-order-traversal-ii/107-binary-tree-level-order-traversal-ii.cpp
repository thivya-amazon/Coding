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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            count = q.size();
            vector<int> slate;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();
                slate.push_back(levelNode->val);
                if(levelNode->left)
                    q.push(levelNode->left);
                if(levelNode->right)
                    q.push(levelNode->right);
            }
            s.push(slate);
        }
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};