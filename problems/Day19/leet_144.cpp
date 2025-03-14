// Pre order traversal
// Iterative Method
//   vector<int> preorderTraversal(TreeNode* root) {
//          vector<int> ans;
//          if(root==NULL) return ans;

//         stack<TreeNode*> s;
//         s.push(root);
//         while(!s.empty()){
//             auto node=s.top();
//             s.pop();
//             ans.push_back(node->val);
//             if(node->right) s.push(node->right);
//             if(node->left) s.push(node->left);
//         }
//         return ans;
//     }