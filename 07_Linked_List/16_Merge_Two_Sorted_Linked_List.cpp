// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Linked_List

// Problem Statement :
/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.


*/

// Approach :
// Time Complexity : O(N+M);
// Space Complexity : O(N+M);

/*

Algorithm: reverse(head, k) 

Method 1 (Using Dummy Nodes) 
The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy. 
The dummy node gives the tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either 'a' or 'b', and adding it to the tail. When 
We are done, the result is in dummy.next.

Method 2 (Using Local References) 
This solution is structurally very similar to the above, but it avoids using a dummy node. Instead, it maintains a struct node** pointer, lastPtrRef, that always points to the last pointer of the result list. This solves the same case that the dummy node did — dealing with the result list when it is empty. If you are trying to build up a list at its tail, either the dummy node or the struct node** "reference" strategy can be used (see Section 1 for details). 

Method 3 (Using Recursion) 
Merge is one of those nice recursive problems where the recursive solution code is much cleaner than the iterative code. You probably wouldn't want to use the recursive version for production code, however, because it will use stack space which is proportional to the length of the lists.  

Method 4 (Reversing The Lists)




This idea involves first reversing both the given lists and after reversing, traversing both the lists till the end and then comparing the nodes of both the lists and inserting the node with a larger value at the beginning of the result list. And in this way we will get the resulting list in increasing order.


1) Initialize result list as empty: head = NULL.

2) Let 'a' and 'b' be the heads of first and second list respectively.

3) Reverse both the lists.

4) While (a != NULL and b != NULL)

    a) Find the larger of two (Current 'a' and 'b')

    b) Insert the larger value of node at the front of result list.

    c) Move ahead in the list of larger node. 

5) If 'b' becomes NULL before 'a', insert all nodes of 'a' 

   into result list at the beginning.

6) If 'a' becomes NULL before 'b', insert all nodes of 'b' 

   into result list at the beginning.  

*/

#include <bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int data;
        cin >> data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin >> data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node *sortedMerge(Node *head1, Node *head2)
{
    // base case
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    Node *finalhead;
    if (head1->data <= head2->data)
    {
        finalhead = head1;
        finalhead->next = sortedMerge(head1->next, head2);
    }
    else
    {
        finalhead = head2;
        finalhead->next = sortedMerge(head1, head2->next);
    }
    return finalhead;
}

// Thank U So Much