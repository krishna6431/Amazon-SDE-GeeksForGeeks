// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : BackTRacking

// Problem Statement :
/*
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then
linked list should be modified to 1->2->4->5. If there are even nodes, then there would be two middle nodes, we need to
delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to
1->2->3->5->6. If the input linked list is NULL or has 1 node, then it should return NULL

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 1 2 4 5

*/

// Approach :
// Time Complexity : O(N);
// Space Complexity : O(1);

/*

Algorithm:
Simple solution: The idea is to first count the number of nodes in a linked list, then delete n/2’th node using the
simple deletion process.

Approach: The above solution requires two traversals of the linked list. The middle node can delete using one traversal.
The idea is to use two pointers, slow_ptr, and fast_ptr. Both pointers start from the head of list. When fast_ptr
reaches the end, slow_ptr reaches middle. This idea is same as the one used in method 2 of this post. The additional
thing in this post is to keep track of the previous middle so the middle node can be deleted.

*/

#include <bits/stdc++.h>
using namespace std;

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

/* Function to get the middle of the linked list*/
struct Node *deleteMid(struct Node *head);
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        head = deleteMid(head);
        printList(head);
    }
    return 0;
}

/* Link list Node:

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list
Node *deleteMid(Node *head)
{
    // My Appraoch to Solve this Problem

    int ans = 0;
    Node *temp = head;
    while (temp)
    {
        ans++;
        temp = temp->next;
    }
    Node *prev = head;
    Node *current = head;
    int middle_id = ans / 2;
    int t = 0;
    while (t++ < middle_id)
    {
        current = current->next;
    }
    t = 0;
    while (t++ < middle_id - 1)
    {
        prev = prev->next;
    }
    prev->next = current->next;
    free(current);
    return head;

    // Fast Pointer and Slow Pointer Method
    // struct Node *deleteMid(struct Node * head)
    // {
    //     // Base cases
    //     if (head == NULL)
    //         return NULL;
    //     if (head->next == NULL)
    //     {
    //         delete head;
    //         return NULL;
    //     }

    //     // Initialize slow and fast pointers
    //     // to reach middle of linked list
    //     struct Node *slow_ptr = head;
    //     struct Node *fast_ptr = head;

    //     // Find the middle and previous of middle.
    //     // To store previous of slow_ptr
    //     struct Node *prev;
    //     while (fast_ptr != NULL && fast_ptr->next != NULL)
    //     {
    //         fast_ptr = fast_ptr->next->next;
    //         prev = slow_ptr;
    //         slow_ptr = slow_ptr->next;
    //     }

    //     // Delete the middle node
    //     prev->next = slow_ptr->next;
    //     delete slow_ptr;

    //     return head;
    // }
}

// Thank U So Much