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
    vector<int> result;
    double minDiff = INT_MAX;
    deque<int> q;
    void dfs(TreeNode* node, double target, int k)
    {
        if(node == NULL)
            return;
        dfs(node->left, target, k);
        if(q.size() == k)
        {
            if(abs(q.front() - target) > abs(node->val - target))
            {
                q.pop_front();
                q.push_back(node->val);
            }
        }
        else
            q.push_back(node->val);
        dfs(node->right, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
       if(root == NULL)
           return result;

        dfs(root, target, k);
        vector<int> ans(q.begin(), q.end());
        return ans;
    }
};