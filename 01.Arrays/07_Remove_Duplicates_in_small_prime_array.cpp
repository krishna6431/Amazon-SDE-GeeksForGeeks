// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array consisting of only prime numbers, remove all duplicate numbers from it.
Note: Retain the first occurrence of the duplicate element.

Example 1:

Input:
N = 6
A[] = {2,2,3,3,7,5}
Output: 2 3 7 5
Explanation: After removing the duplicate
2 and 3 we get 2 3 7 5.

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(n);
Approach: The time complexity in this method can be reduced but space complexity will take a toll. This involves the use
of Hashing where the numbers are marked in a HashMap, so that if the number is again encountered then erase it from the
array.

Algorithm:
  1. Use a hash set. HashSet stores only unique elements.

  2. It is known that if two same elements are put into a HashSet the HashSet stores only one element (all the duplicate
element vanishes)

  3.Traverse the array from start to end.

  4.For every element, insert the element in HashSet

  5.Now Traverse the HashSet and put the elements in the HashSet in the array
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int> &arr, int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        vector<int> result = removeDuplicate(A, N);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}
// } Driver Code Ends

vector<int> removeDuplicate(vector<int> &ve, int n)
{
    // code here
    int h[100] = {0};
    for (int i = 0; i < n; i++)
        h[ve[i]]++;
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (h[ve[i]] >= 1)
        {
            v.push_back(ve[i]);
            h[ve[i]] = 0;
        }
    return v;
}
