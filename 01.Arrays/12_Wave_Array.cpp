// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array and return it. In other words,
arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing
lexicographical order).

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
Explanation: Array elements after
sorting it in wave form are
2 1 4 3 5.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(n);


Approach:This can be done in O(n) time by doing a single traversal of given array. The idea is based on the fact that if
we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their adjacent odd elements, we
don’t need to worry about odd positioned element. Following are simple steps. 1) Traverse all even positioned elements
of input array, and do following. ….a) If current element is smaller than previous odd element, swap previous and
current. ….b) If current element is smaller than next odd element, swap next and current.

*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to convert given array to wave like array
// arr: input array
// n: size of array
void convertToWave(int *arr, int n)
{

    // code is writteb by Krishna
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

// { Driver Code Starts.

int main()
{
    int t, n;
    cin >> t;   // Input testcases
    while (t--) // While testcases exist
    {
        cin >> n; // input size of array
        int a[n]; // declare array of size n
        for (int i = 0; i < n; i++)
            cin >> a[i]; // input elements of array

        convertToWave(a, n);

        for (int i = 0; i < n; i++)
            cout << a[i] << " "; // print array

        cout << endl;
    }
} // } Driver Code Ends