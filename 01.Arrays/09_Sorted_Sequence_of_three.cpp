// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*

Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Example 1:

Input:
N = 5
A[] = {1,2,1,1,3}
Output: 1
Explanation: a sub-sequence 1 2 3 exist.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(1);

Approach:
Hint: Use Auxiliary Space.
Solution: So, the main motive is to find an element which has an element smaller than itself on the left side of the
array and an element greater than itself on the right side of the array, if there is any such element then there exists
a triplet that satisfies the criteria.

Approach: This can be solved in a very simple way. To find an element which has an element smaller than itself on its
left side of the array, check if that element is the smallest element while traversing the array from the starting index
i.e., (0), and to check if there is an element greater than itself on its right side of the array check whether that
element is the largest element while traversing from the end of the array i.e., (n-1). If the element is not the
smallest element from 0 to that index then it has an element smaller than itself on its left side, and similarly, if the
element is not the largest element from that index to the last index then there is a larger element on its right side.

Algorithm :
1-->Create an auxiliary array smaller[0..n-1]. smaller[i] stores the index of a number which is smaller than arr[i] and
is on the left side. The array contains -1 if there is no such element. 2-->Create another auxiliary array
greater[0..n-1]. greater[i] stores the index of a number which is greater than arr[i] and is on the right side of
arr[i]. The array contains -1 if there is no such element. 3-->Finally traverse both smaller[] and greater[] and find
the index [i] for which both smaller[i] and greater[i] are not equal to -1.
*/

#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m)
{

    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (v1[n - 1] == v2[m - 1])
        return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

vector<int> find3Numbers(vector<int>, int);

// Driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        auto res = find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3)
        {
            cout << -1 << "\n";
        }

        if (res.empty())
        {
            cout << 0 << "\n";
        }
        else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(a, res, n, res.size()))
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
} // } Driver Code Ends

/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> arr, int N)
{
    // Code is Written By Krishna
    vector<int> smLeft(N, INT_MAX), larRig(N, INT_MIN);

    for (int i = 1; i < N; ++i)
    {
        smLeft[i] = min(arr[i - 1], smLeft[i - 1]); // stroring the smallest elemnt on left
    }

    for (int i = N - 2; i >= 0; --i)
    {
        larRig[i] = max(arr[i + 1], larRig[i + 1]); // storing the largest element on right
    }

    vector<int> ans;

    for (int i = 0; i < N; ++i)
    {
        if (smLeft[i] < arr[i] &&
            arr[i] < larRig[i]) // if conditions are valid(because above approach also conatins similar elements too)
        {
            ans.push_back(smLeft[i]);
            ans.push_back(arr[i]);
            ans.push_back(larRig[i]);
            return ans;
        }
    }

    return ans;
}
