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
    vector<TreeNode*> result;
    void bfs(TreeNode* root, unordered_set<int>& uset)
    {
        queue<TreeNode*> q;
        q.push(root);
        if(uset.count(root->val) == 0)
            result.push_back(root);
            
        while(!q.empty())
        {
            TreeNode* levelNode = q.front();
            q.pop();

            if(levelNode->left)
            {
                q.push(levelNode->left);
                if(uset.count(levelNode->left->val))
                    levelNode->left = NULL;
                else if(uset.count(levelNode->val))
                    result.push_back(levelNode->left);
            }
            if(levelNode->right)
            {
                q.push(levelNode->right);
                if(uset.count(levelNode->right->val))
                    levelNode->right = NULL;
                else if(uset.count(levelNode->val))
                    result.push_back(levelNode->right);
            }

        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root)
            return result;
        unordered_set<int> uset(to_delete.begin(), to_delete.end());
        bfs(root, uset);
        return result;
    }
};