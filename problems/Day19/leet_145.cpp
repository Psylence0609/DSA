// Post order traversal

// Iterative method with 2 stacks :
//  vector<int> postorderTraversal(TreeNode *root)
//  {
//      vector<int> ans;
//      if (root == nullptr)
//          return ans;
//      stack<TreeNode *> st1;
//      stack<TreeNode *> st2;
//      st1.push(root);
//      while (!st1.empty())
//      {
//          TreeNode *node = st1.top();
//          st1.pop();
//          st2.push(node);
//          if (node->left)
//              st1.push(node->left);
//          if (node->right)
//              st1.push(node->right);
//      }
//      while (!st2.empty())
//      {
//          ans.push_back(st2.top()->val);
//          st2.pop();
//      }
//      return ans;
//  }

// Iterative method with 1 stack

// vector<int> postorderTraversal(TreeNode *root)
// {
//     vector<int> ans;
//     stack<TreeNode *> st;
//     TreeNode *curr = root;
//     TreeNode *temp;
//     while (curr != nullptr || !st.empty())
//     {
//         if (curr != nullptr)
//         {
//             st.push(curr);
//             curr = curr->left;
//         }
//         else
//         {
//             temp = st.top()->right;
//             if (temp == nullptr)
//             {
//                 temp = st.top();
//                 st.pop();
//                 ans.push_back(temp->val);
//                 while (!st.empty() && st.top()->right == temp)
//                 {
//                     temp = st.top();
//                     st.pop();
//                     ans.push_back(temp->val);
//                 }
//             }
//             else
//             {
//                 curr = temp;
//             }
//         }
//     }
//     return ans;
// }