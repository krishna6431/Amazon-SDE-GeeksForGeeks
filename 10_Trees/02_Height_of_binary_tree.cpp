// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Trees

// Problem Statement :
/*
Given a binary tree, find its height.


Example 1:

Input:
     1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   
*/

// Approach :
// Time Complexity : O(N);
// Space Complexity : O(N);

/*

Given a binary tree, find height of it. Height of empty tree is 0 and height of below tree is 2. 
 


Example Tree
Recursively calculate height of left and right subtrees of a node and assign height to the node as max of the heights of two children plus 1. See below pseudo code and program for details.
Algorithm: 


 maxDepth()

1. If tree is empty then return 0

2. Else

     (a) Get the max depth of left subtree recursively  i.e., 

          call maxDepth( tree->left-subtree)

     (a) Get the max depth of right subtree recursively  i.e., 

          call maxDepth( tree->right-subtree)

     (c) Get the max of max depths of left and right 

          subtrees and add 1 to it for the current node.

         max_depth = max(max dept of left subtree,  

                             max depth of right subtree) 

                             + 1

     (d) Return max_depth

See the below diagram for more clarity about execution of the recursive function maxDepth() for above example tree. 


            maxDepth('1') = max(maxDepth('2'), maxDepth('3')) + 1

                               = 1 + 1

                                  /    \

                                /         \

                              /             \

                            /                 \

                          /                     \

               maxDepth('2') = 1                maxDepth('3') = 0

= max(maxDepth('4'), maxDepth('5')) + 1

= 1 + 0   = 1         

                   /    \

                 /        \

               /            \

             /                \

           /                    \

 maxDepth('4') = 0     maxDepth('5') = 0


*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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

            // Create the left child for the current Node
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

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    //Function to find the height of a binary tree.
    // My Solution
    int height(struct Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int max = 0;
        int childHeight = height(root->left);
        if (childHeight > max)
        {
            max = childHeight;
        }

        childHeight = height(root->right);
        if (childHeight > max)
        {
            max = childHeight;
        }
        return max + 1;
    }

    // GFG Editorial Solution
    // int maxDepth(node *node)
    // {
    //     if (node == NULL)
    //         return 0;
    //     else
    //     {
    //         /* compute the depth of each subtree */
    //         int lDepth = maxDepth(node->left);
    //         int rDepth = maxDepth(node->right);

    //         /* use the larger one */
    //         if (lDepth > rDepth)
    //             return (lDepth + 1);
    //         else
    //             return (rDepth + 1);
    //     }
    // }
};

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.height(root) << endl;
    }
    return 0;
}

//Thank U So Much