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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<pair<TreeNode*,string>> s;
        s.push({root, "arrival"});
        while(!s.empty())
        {
            TreeNode* node = s.top().first;
            string zone = s.top().second;
            if(zone == "arrival")
            {
                //Update the zone
                zone = "interim";
                s.pop();
                s.push({node, zone});
                //Visit the node
                result.push_back(node->val);
                if(node->left)
                    s.push({node->left, "arrival"});
            }
            else if(zone == "interim")
            {
                zone = "departure";
                s.pop();
                s.push({node, zone});
                if(node->right)
                    s.push({node->right, "arrival"});
            }
            else if(zone == "departure")
            {
                s.pop();
            }
        }
        return result;
    }
};