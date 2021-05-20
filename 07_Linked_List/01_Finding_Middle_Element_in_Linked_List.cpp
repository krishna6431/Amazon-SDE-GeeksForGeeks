// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given a singly linked list of N nodes. The task is to find the middle of the linked list. For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.

*/

// Approach :
// Time Complexity : O(N);
// Space Complexity : O(1);

/*
Algorithm:
Given a singly linked list, find the middle of the linked list. For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4. 

Method 1: 
Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. 

Method 2: 
Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.
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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
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
        cout << getMiddle(head) << endl;
    }
    return 0;
}
/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    int ans = 0;
    Node *temp = head;
    while (temp)
    {
        ans++;
        temp = temp->next;
    }
    int middle_id = ans / 2;
    int t = 0;
    while (t++ < middle_id)
    {
        head = head->next;
    }
    return head->data;

    // Slow Pointer and Fast Pointer Method
    // Node *slow_ptr = head;
    // Node *fast_ptr = head;

    // if (head!=NULL)
    // {
    //     while (fast_ptr != NULL && fast_ptr->next != NULL)
    //     {
    //         fast_ptr = fast_ptr->next->next;
    //         slow_ptr = slow_ptr->next;
    //     }
    //     printf("The middle element is [%d]\n\n", slow_ptr->data);
    // }
}

//Thank U So Much
