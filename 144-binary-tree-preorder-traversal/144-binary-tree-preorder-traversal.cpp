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
        ARRIVAL = 0,
        INTERIM,
        DEPARTURE            
    };
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<pair<TreeNode*,Zones>> s;
        s.push({root, ARRIVAL});
        while(!s.empty())
        {
            TreeNode* node = s.top().first;
            Zones zone = s.top().second;
            if(zone == ARRIVAL)
            {
                //Update the zone
                zone = INTERIM;
                s.pop();
                s.push({node, zone});
                //Visit the node
                result.push_back(node->val);
                if(node->left)
                    s.push({node->left, ARRIVAL});
            }
            else if(zone == INTERIM)
            {
                zone = DEPARTURE;
                s.pop();
                s.push({node, zone});
                if(node->right)
                    s.push({node->right, ARRIVAL});
            }
            else if(zone == DEPARTURE)
            {
                s.pop();
            }
        }
        return result;
    }
};