// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

Example 1:

Input:
N = 1
A[] = {1}
Output: 1
Explanation: Since its the only 
element hence its the only equilibrium 
point. 

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(1);


Approach:The idea is to get total sum of array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. In the loop, we can get right sum by subtracting the elements one by one.

*/

// Position this line where user code will be pasted.

// Position this line where user code will be pasted.
#include <bits/stdc++.h>
using namespace std;

int equilibriumPoint(long long a[], int n);

int main()
{

    long long t;

    //taking testcases
    cin >> t;

    while (t--)
    {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        //calling equilibriumPoint() function
        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long a[], int n)
{
    // Your code here
    long long su = 0;
    for (long long i = 0; i < n; i++)
    {
        su += a[i];
    }
    long long s = 0;
    int flag = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        s += a[i];

        if (s == su)
        {
            flag = 1;
            break;
        }
        su -= a[i];
    }
    if (flag)
    {
        return i + 1;
    }
    else
    {
        return -1;
    }
}