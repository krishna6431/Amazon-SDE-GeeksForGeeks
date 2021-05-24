// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Stacks

// Problem Statement :
/*
Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.


// Approach :
// Time Complexity : O(N);
// Space Complexity : O(N);

/*

Algorithm: 


Method 1 (Simple) 
Use two loops: The outer loop picks all the elements one by one. The inner loop looks for the first greater element for the element picked by the outer loop. If a greater element is found then that element is printed as next, otherwise, -1 is printed.

Method 2 (Using Stack) 


Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop. 
    Mark the current element as next.
    If stack is not empty, compare top element of stack with next.
    If next is greater than the top element, Pop element from stack. next is the next greater element for the popped element.
    Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements.
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from the stack and print -1 as the next element for them.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        // Code is Written By Krishna
        stack<long long> stk;
        vector<long long> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top() <= arr[i])
            {
                stk.pop();
            }
            if (stk.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = stk.top();
            }
            stk.push(arr[i]);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

//Thank U So Much