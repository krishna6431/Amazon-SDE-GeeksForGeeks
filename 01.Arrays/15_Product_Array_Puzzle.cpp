// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all
the elements of A except A[i].



Example 1:

Input:
N = 5
A[] = {10, 3, 5, 6, 2}
Output: 180 600 360 300 900
Explanation:
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(n);


Approach:
1. Compute product of all elements of array in prod(let).
Now start traversing array print the quotient of prod dividing by current element i.e. arr[i]. Do this for remaining
elements.

*/

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int> &, int);

// your code will be pasted here

int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }

        vec = productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    // code here
    long long int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= nums[i];
    }
    vector<long long int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            long long int prd = 1;
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                {
                    prd *= nums[j];
                }
            }
            ans.push_back(prd);
            continue;
        }
        ans.push_back(m / nums[i]);
    }
    return ans;
}
