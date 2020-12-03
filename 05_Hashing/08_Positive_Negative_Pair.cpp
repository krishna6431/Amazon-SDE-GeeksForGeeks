// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

// Problem Statement :
/*
Given an array of distinct integers, find all the pairs having negative and positive value of a number that exists in
the array.

Example 1:

Input:
N = 8
arr[] = {1,3,6,-2,-1,-3,2,7}
Output: -1 1 -3 3 -2 2
Explanation: 1, 3 and 2 are present
pairwirse postive and negative. 6 and
7 have no pair.
*/

// Approach :
// Time Complexity : O(n);
// Space Complexity : O(n);
/*
The idea is to use hashing. Traverse the given array, increase the count at absolute value of hash table. If count
becomes 2, store its absolute value in another vector. And finally sort the vector. If the size of the vector is 0,
print "0", else for each term in vector print first its negative value and the the positive value.
*/

// Initial function template for C++

#include <bits/stdc++.h>
#include <math.h>
#include <unordered_map>
using namespace std;

vector<int> findPairs(int *, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res = findPairs(arr, n);
        if (res.size() != 0)
        {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
} // } Driver Code Ends

// User function template for C++

vector<int> findPairs(int arr[], int n)
{
    // code written by krishna
    vector<int> v;
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        if (m[abs(arr[i])] == 0)
        {
            m[abs(arr[i])] = 1;
        }
        else
        {
            v.push_back(abs(arr[i]));
            m[abs(arr[i])] = 0;
        }
    }
    if (v.size() == 0)
    {
        v.push_back(0);
        return v;
    }
    else
    {
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
        {
            ans.push_back(-v[i]);
            ans.push_back(v[i]);
        }
        return ans;
    }
}