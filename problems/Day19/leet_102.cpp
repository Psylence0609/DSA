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
// Level Order Traversal
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        vector<TreeNode *> level;
        int i = 1;
        while (true)
        {
            vector<TreeNode *> temp;
            vector<int> temp1;
            if (i)
            {
                level.push_back(root);
                i = 0;
            }

            for (auto &node : level)
            {
                if (node)
                {
                    temp1.push_back(node->val);
                    if (node->left)
                        temp.push_back(node->left);
                    if (node->right)
                        temp.push_back(node->right);
                }
            }
            if (temp1.size())
                ans.push_back(temp1);
            if (temp.size() == 0)
                break;
            level = temp;
        }
        return ans;
    }
};