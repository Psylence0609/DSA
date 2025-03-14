// inorder traversal

// vector<int> ans;
// vector<int> dum;
// vector<int> inorderTraversal(TreeNode *root)
// {
//     if (root == NULL)
//         return dum;
//     dum = inorderTraversal(root->left);
//     ans.push_back(root->val);
//     dum = inorderTraversal(root->right);
//     return ans;
// }

// Iterative method:

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int>ans;
//     stack<TreeNode*>st;

//     while(root  || !st.empty())
//     {
//         while(root)
//         {
//             st.push(root);
//             root=root->left;
//         }

//         root=st.top();
//         st.pop();
//         ans.push_back(root->val);
//         root=root->right;
//     }

//     return ans;
// }