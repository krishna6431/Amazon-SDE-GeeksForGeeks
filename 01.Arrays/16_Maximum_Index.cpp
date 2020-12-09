// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Example 1:

Input:
N = 2
A[] = {1,10}
Output: 1
Explanation: A[0]<=A[1] so (j-i) 
is 1-0 = 1.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(n);


Approach: 
As we need the max difference j - i such that A[i]<= A[j], hence we do not need to consider element after the index j and element before index i.

But why..???

Lets say, we get max difference for a particular i and j. Then these conditions hold true.

A[i] <= A[j]
Any element before A[i] is larger then A[j], else it would make the max difference. Hence we do not consider any element before A[i].
Any element after A[j] is smaller then A[i], else it would make the max difference. Hence we do not consider any element after A[j].
Now on basis of this analysis, how can we solve the question..?

For the observation, in previous hint, make 2 arrays, 
First, will store smallest occuring element before the element
Second, will store largest occuring element after the element

Traverse the Second array, till the element in second array is larger than or equal to First array, and store the index difference. And if it becomes smaller, traverse the first array till it again becomes larger.

And store the max difference of this index difference.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array
int maxIndexDiff(int arr[], int n)
{

    // code is written by krishna
    int LMin[n];
    int RMax[n];
    LMin[0] = arr[0];
    for (int i = 1; i < n; ++i)
        LMin[i] = min(arr[i], LMin[i - 1]);

    RMax[n - 1] = arr[n - 1];
    for (int j = n - 2; j >= 0; --j)
        RMax[j] = max(arr[j], RMax[j + 1]);

    int i = 0, j = 0, maxDiff = 0;
    while (j < n && i < n)
    {
        if (LMin[i] <= RMax[j])
        {
            maxDiff = max(maxDiff, j - i);
            j = j + 1;
        }
        else
            i = i + 1;
    }

    return maxDiff;
}

// { Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    //testcases
    cin >> T;
    while (T--)
    {
        int num;
        //size of array
        cin >> num;
        int arr[num];

        //inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        //printing 0 if size is 1
        if (num == 1)
        {
            cout << 0 << endl;
            continue;
        }

        //calling maxIndexDiff() function
        cout << maxIndexDiff(arr, num) << endl;
    }
    return 0;
} // } Driver Code Ends