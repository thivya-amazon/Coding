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
    void bfs(TreeNode* root, map<int, vector<int>>& m)
    {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int count = 0;
        while(!q.empty())
        {
            count = q.size();
            multiset<pair<int,int>> s;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front().first;
                int col = q.front().second;
                q.pop();
                s.insert({col, levelNode->val});
                if(levelNode->left)
                    q.push({levelNode->left, col-1});
                if(levelNode->right)
                    q.push({levelNode->right, col+1});
            }
            for(auto i : s)
                m[i.first].push_back(i.second);
        }

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL)
           return result; 
        map<int, vector<int>> m;
        bfs(root, m);
        for(auto i : m)
            result.push_back(i.second);
         return result;
    }
};