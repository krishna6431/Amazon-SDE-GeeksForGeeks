// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Trees

// Problem Statement :
/*
Given a Binary Tree. Check whether the Binary tree is a full binary tree or not.

Example 1:

Input:
          1
       /    \
      2      3
    /   \
   4     5
Output: 1
Explanation: Every node except leaf node
has two children so it is a full tree.
Example 2:

Input:
          1
       /    \
      2      3
    /   
   4     
Output: 0
Explanation: Node 2 has only one child
so this is not a full tree.


// Approach :
// Time Complexity : O(N);
// Space Complexity : O(height of tree);

/*

To check whether a binary tree is a full binary tree we need to test the following cases:-
1) If a binary tree node is NULL then it is a full binary tree. 
2) If a binary tree node does have empty left and right sub-trees, then it is a full binary tree by definition. 
3) If a binary tree node has left and right sub-trees, then it is a part of a full binary tree by definition. In this case recursively check if the left and right sub-trees are also binary trees themselves. 
4) In all other combinations of right and left sub-trees, the binary tree is not a full binary tree.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str)
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

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isFullTree(struct Node *root);
int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        cout << isFullTree(root) << endl;
    }
}

/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Return True if the given Binary Tree is a Full Binary Tree. Else return False

bool isFullTree(struct Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left && root->right)
        return isFullTree(root->left) && isFullTree(root->right);
    return false;
}

//Thank U So Much