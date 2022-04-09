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
    enum Zones{
        ARRIVAL,
        INTERIM,
        DEPARTURE
    };
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<pair<TreeNode*, Zones>> s;
        s.push({root, ARRIVAL});
        while(!s.empty())
        {
            TreeNode* node = s.top().first;
            Zones currZone = s.top().second;
            if(currZone == ARRIVAL)
            {
                currZone = INTERIM;
                s.pop();
                s.push({node, currZone});
                if(node->left)
                    s.push({node->left, ARRIVAL});
            }
            else if(currZone == INTERIM)
            {
                currZone = DEPARTURE;
                s.pop();
                s.push({node, currZone});
                if(node->right)
                    s.push({node->right, ARRIVAL});
            }
            else if(currZone == DEPARTURE)
            {
                s.pop();
                result.push_back(node->val);
            }
        }
        return result;
        
    }
};