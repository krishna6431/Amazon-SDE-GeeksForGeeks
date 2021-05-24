// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Stacks

// Problem Statement :
/*
Write a program to implement a Stack using Array. Your task is to use the class as shown in the comments in the code
editor and complete the functions push() and pop() to implement a stack.

Example 1:

Input:
push(2)
push(3)
pop()
push(4)
pop()
Output: 3, 4
Explanation:
push(2)    the stack will be {2}
push(3)    the stack will be {2 3}
pop()      poped element will be 3,
           the stack will be {2}
push(4)    the stack will be {2 4}
pop()      poped element will be 4
Example 2:

Input:
pop()
push(4)
push(5)
pop()
Output: -1, 5


// Approach :
// Time Complexity : O(1);
// Space Complexity : O(1);

/*
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may
be LIFO(Last In First Out) or FILO(First In Last Out).


Mainly the following three basic operations are performed in the stack:


Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack
is empty, then it is said to be an Underflow condition. Peek or Top: Returns top element of stack. isEmpty: Returns true
if stack is empty, else false. stack How to understand a stack practically? There are many real-life examples of a
stack. Consider the simple example of plates stacked over one another in a canteen. The plate which is at the top is the
first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the
longest period of time. So, it can be simply seen to follow LIFO/FILO order.


Time Complexities of operations on stack:




push(), pop(), isEmpty() and peek() all take O(1) time. We do not run any loop in any of these operations.



Applications of stack:


Balancing of symbols
Infix to Postfix /Prefix conversion
Redo-undo features at many places like editors, photoshop.
Forward and backward feature in web browsers
Used in many algorithms like Tower of Hanoi, tree traversals, stock span problem, histogram problem.
Backtracking is one of the algorithm designing technique .Some example of back tracking are Knight-Tour problem,N-Queen
problem,find your way through maze and game like chess or checkers in all this problems we dive into someway if that way
is not efficient we come back to the previous state and go into some another path. To get back from current state we
need to store the previous state for that purpose we need stack. In Graph Algorithms like Topological Sorting and
Strongly Connected Components In Memory management any modern  computer uses stack as the primary-management for a
running purpose.Each program that is running in a computer system has its own memory allocations String reversal is also
a another application of stack.Here one by one each character get inserted into the stack.So the first character of
string is on the bottom of the stack and the last element of string is on the top of stack. After Performing the pop
operations on stack we get string in reverse order .


Implementation:
There are two ways to implement a stack:


Using array
Using linked list

*/

#include <bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                sq->push(a);
            }
            else if (QueryType == 2)
            {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// Function to push an integer into the stack.
void MyStack ::push(int x)
{
    StackNode *temp = new StackNode(x);
    temp->next = top;
    top = temp;
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (this->top == NULL)
        return -1;
    int x = this->top->data;
    StackNode *temp = this->top;
    this->top = this->top->next;
    free(temp);
    return x;
}

// Thank U So Much