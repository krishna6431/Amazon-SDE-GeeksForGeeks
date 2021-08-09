// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Linked_List

// Problem Statement :
/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.


*/

// Approach :
// Time Complexity : O(NLogN;
// Space Complexity : O(N);

/*
Algorithm: 

Let the head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so the head node has to be changed if the data at the original head is not the smallest value in the linked list. 


MergeSort(headRef)

1) If the head is NULL or there is only one element in the Linked List 

    then return.

2) Else divide the linked list into two halves.  

      FrontBackSplit(head, &a, &b);

3) Sort the two halves a and b.

      MergeSort(a);

MergeSort(b);

4) Merge the sorted a and b (using SortedMerge() discussed here) 

   and update the head pointer using headRef.

     *headRef = SortedMerge(a, b);

     Approach 2: This approach is simpler and uses log n space.



Approach 2:
mergeSort():


If the size of the linked list is 1 then return the head
Find mid using The Tortoise and The Hare Approach
Store the next of mid in head2 i.e. the right sub-linked list.
Now Make the next midpoint null.
Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
Return the final head of the merged linkedlist.

merge(head1, head2):


Take a pointer say merged to store the merged list in it and store a dummy node in it.
Take a pointer temp and assign merge to it.
If the data of head1 is less than the data of head2, then, store head1 in next of temp & move head1 to the next of head1.
Else store head2 in next of temp & move head2 to the next of head2.
Move temp to the next of temp.
Repeat steps 3, 4 & 5 until head1 is not equal to null and head2 is not equal to null.
Now add any remaining nodes of the first or the second linked list to the merged linked list.
Return the next of merged(that will ignore the dummy and return the head of the final merged linked list)

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
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

    Node *midPoint(Node *head)
    {
        Node *slow_ptr = head;
        Node *fast_ptr = head->next;

        while (fast_ptr != NULL and fast_ptr->next != NULL)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
        }
        return slow_ptr;
    }
    //Function to sort the given linked list using Merge Sort.
    Node *mergeSort(Node *head)
    {
        //base case
        if (head == NULL or head->next == NULL)
        {
            return head;
        }
        //rec case
        Node *mid = midPoint(head);

        //break at mid point
        Node *a = head;
        Node *b = mid->next;
        mid->next = NULL;

        //recursive cases
        a = mergeSort(a);
        b = mergeSort(b);

        //merge case
        return sortedMerge(a, b);
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}

// Thank U So Much
