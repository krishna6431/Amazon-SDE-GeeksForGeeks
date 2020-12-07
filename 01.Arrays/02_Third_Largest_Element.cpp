// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array of distinct elements. Find the third largest element in it.

Example 1:

Input:
N = 5
A[] = {2,4,1,3,5}
Output: 3

*/

// Time Complexity : O(n);
// Space Complexity : O(1);
/*
Efficient Approach: The problem deals with finding the third largest element in the array in a single traversal. The
problem can be cracked by taking help of a similar problem- finding the second maximum element. So the idea is to
traverse the array from start to end and to keep track of the three largest elements up to that index (stored in
variables). So after traversing the whole array, the variables would have stored the indices (or value) of the three
largest elements of the array.

Algorithm:
    1.Create three variables, first, second, third, to store indices of three largest elements of the array. (Initially
all of them are initialized to a minimum value).

    2.Move along the input array from start to the end.

    3.For every index check if the element is larger than first or not. Update the value of first, if the element is
larger, and assign the value of first to second and second to third. So the largest element gets updated and the
elements previously stored as largest becomes second largest, and the second largest element becomes third largest.

    4.Else if the element is larger than the second, then update the value of second,and the second largest element
becomes third largest.

    5.If the previous two conditions fail, but the element is larger than the third, then update the third.

    6.Print the value of third after traversing the array from start to end
*/

#include <bits/stdc++.h>
using namespace std;
int thirdLargest(int a[], int n);

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
        cout << thirdLargest(a, n) << endl;
    }
}

int thirdLargest(int arr[], int n)
{
    if (n == 1 || n == 2)
    {
        return -1;
    }
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr[n - 3];
}
