#include <bits/stdc++.h>
using namespace std;

// Tree TreeNode
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> verticalTraversal(TreeNode *root);
static bool sort_func(pair<TreeNode *, pair<int, int>> a, pair<TreeNode *, pair<int, int>> b);

// Utility function to create a new Tree TreeNode
TreeNode *newNode(int val)
{
    TreeNode *temp = new TreeNode;
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
TreeNode *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    TreeNode *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<TreeNode *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        TreeNode *currNode = queue.front();
        queue.pop();

        // Get the current TreeNode's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current TreeNode
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current TreeNode
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    scanf("%d ", &t);
    string s;
    getline(cin, s);
    TreeNode *root = buildTree(s);
    vector<vector<int>> vec = verticalTraversal(root);
    for (auto x : vec)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}

static bool sort_func(pair<TreeNode *, pair<int, int>> a, pair<TreeNode *, pair<int, int>> b)
{
    if (a.second.second == b.second.second)
        return a.second.first < b.second.first;
    return a.second.second < b.second.second;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    vector<pair<TreeNode *, pair<int, int>>> cord;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<TreeNode *, pair<int, int>> temp = q.front();

        q.pop();

        cord.push_back(temp);

        if (temp.first->left)
            q.push(make_pair(temp.first->left, make_pair(temp.second.first + 1, temp.second.second - 1)));

        if (temp.first->right)
            q.push(make_pair(temp.first->right, make_pair(temp.second.first + 1, temp.second.second + 1)));
    }

    sort(cord.begin(), cord.end(), sort_func);
    for (auto x : cord)
    {
        cout << x.first->val << " " << x.second.first << " " << x.second.second << endl;
    }
    int level = cord[0].second.second;
    for (int i = 0; i < cord.size(); i++)
    {
        vector<int> temp;
        while (true)
        {
            if (cord[i].second.second == level)
            {
                temp.push_back(cord[i].first->val);
                i++;
            }
            else
            {
                level = cord[i].second.second;
                break;
            }
        }
        ans.push_back(temp);
    }

    return ans;
}
