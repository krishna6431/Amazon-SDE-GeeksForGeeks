// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Linked_List

// Problem Statement :
/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked
list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5
Explanation:
The first 4 elements 1,2,2,4 are reversed first
and then the next 4 elements 5,6,7,8. Hence, the
resultant linked list is 4->2->2->1->8->7->6->5.

*/

// Approach :
// Time Complexity : O(N);
// Space Complexity : O(1);

/*

Algorithm: reverse(head, k)

1->Reverse the first sub-list of size k. While reversing keep track of the next node and previous node. Let the pointer
to the next node be next and pointer to the previous node be prev. See this post for reversing a linked list.
2->head->next = reverse(next, k) ( Recursively call for rest of the list and link the two sub-lists )
3->Return prev ( prev becomes the new head of the list (see the diagrams of an iterative method of this post) )

*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
    struct node
    {
        int data;
        struct node* next;

        node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution
{
  public:
    struct node *reverse(struct node *head, int k)
    {
        // base case
        if (head == NULL)
        {
            return NULL;
        }

        // reverse first k node
        node *current = head;
        node *prev = NULL;
        node *temp;
        int count = 1;
        while (current != NULL && count <= k)
        {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            count++;
        }

        if (temp != NULL)
        {
            // trickier case think using pen paper
            head->next = reverse(temp, k);
        }
        return prev;
    }
};

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }

    return (0);
}

// Thank U So Much