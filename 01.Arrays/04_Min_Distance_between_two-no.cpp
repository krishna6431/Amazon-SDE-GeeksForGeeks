// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
You are given an array A, of N elements. Find minimum index based distance between two elements of the array, x and y.

Example 1:

Input:
N = 4
A[] = {1,2,3,2}
x = 1, y = 2
Output: 1
Explanation: x = 1 and y = 2. There are
two distances between x and y, which are
1 and 3 out of which the least is 1.

*/

// Time Complexity : O(n);
// Space Complexity : O(1);
/*
Approach: So the basic approach is to check only consecutive pairs of x and y. For every element x or y, check the index
of the previous occurrence of x or y and if the previous occurring element is not similar to current element update the
minimum distance. But a question arises what if an x is preceded by another x and that is preceded by a y, then how to
get the minimum distance between pairs. By analyzing closely it can be seen that every x followed by a y or vice versa
can only be the closest pair (minimum distance) so ignore all other pairs.

Algorithm:
  1. Create a variable prev=-1 and m= INT_MAX
  2. Traverse through the array from start to end.
  3. If the current element is x or y, prev is not equal to -1 and array[prev] is not equal to current element then
update m = max(current_index - prev, m), i.e. find the distance between consecutive pairs and update m with it.
  4. print the value of m
*/

#include <bits/stdc++.h>
using namespace std;
int minDist(int arr[], int n, int x, int y);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int x, y;
        cin >> x >> y;
        cout << minDist(a, n, x, y) << endl;
    }
    return 0;
}
// } Driver Code Ends

int minDist(int arr[], int n, int x, int y)
{
    // code here
    int p = -1, mi = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            if (p != -1 && arr[i] != arr[p])
            {
                mi = min(mi, i - p);
            }
            p = i;
        }
    }
    if (mi == INT_MAX)
    {
        return -1;
    }
    return mi;
}