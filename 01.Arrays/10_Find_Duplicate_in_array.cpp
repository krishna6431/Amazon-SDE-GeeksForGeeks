// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Example 1:

Input:
N = 4
a[] = {0,3,1,2}
Output: -1
Explanation: N=4 and all elements from 0
to (N-1 = 3) are present in the given
array. Therefore output is -1.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(1);


Approach: The basic idea is to use a HashMap to solve the problem. But there is a catch, the numbers in the array are from 0 to n-1, and the input array has length n. So, the input array can be used as a HashMap. While traversing the array, if an element a is encountered then increase the value of a%n'th element by n. The frequency can be retrieved by dividing the a%n'th element by n.

Algorithm:  

1-->Traverse the given array from start to end.
2-->For every element in the array increment the arr[i]%n'th element by n.
3-->Now traverse the array again and print all those indices i for which arr[i]/n is greater than 1. Which guarantees that the number n has been added to that index.

Note: This approach works because all elements are in the range from 0 to n-1 and arr[i]/n would be greater than 1 only if a value "i" has appeared more than once. 

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<int> duplicates(int arr[], int n)
{
    vector<int> res;
    vector<int> temp(n, 0);
    for (int i = 0; i < n; i++)
    {
        temp.at(arr[i])++;
    }

    for (int i = 0; i < n; i++)
    {
        if (temp.at(i) > 1)
        {
            res.push_back(i);
        }
    }
    if (res.empty())
    {
        res.push_back(-1);
        return res;
    }
    else
        return res;
}
