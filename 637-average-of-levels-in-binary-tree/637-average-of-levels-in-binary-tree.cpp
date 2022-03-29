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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
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
            double sum = 0;
            for(int i = 0; i < slate.size(); i++)
                 sum += slate[i];
            result.push_back((double)sum/slate.size());
        }
        return result;
    }
};