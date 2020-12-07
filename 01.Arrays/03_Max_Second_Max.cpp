// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given an array arr[] of size N of positive integers which may have duplicates. The task is to find the maximum and
second maximum from the array, and both of them should be distinct, so If no second max exists, then the second max will
be -1.

Example 1:

Input:
N = 3
arr[] = {2,1,2}
Output: 2 1
Explanation: From the given array
elements, 2 is the largest and 1
is the second largest.

*/

// Time Complexity : O(n);
// Space Complexity : O(1);

#include <bits/stdc++.h>
using namespace std;

vector<int> largestAndSecondLargest(int, int[]);

// } Driver Code Ends

/* Function to find largest and second largest element
 *sizeOfArray : number of elements in the array
 * arr = input array
 */

// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

vector<int> largestAndSecondLargest(int n, int arr[])
{
    int max = INT_MIN, max2 = INT_MIN;

    /*********************************
     Code is witten by Krishna
     * *******************************/
    set<int> v;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        v.insert(arr[i]);
    }
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        temp.push_back(*itr);
    }
    //  for(auto x:v){
    //      cout << x << " ";
    //  }
    vector<int> ans;
    if (temp.size() == 1)
    {
        ans.push_back(temp[temp.size() - 1]);
        ans.push_back(-1);
    }
    else if (temp.size() == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        ans.push_back(temp[temp.size() - 1]);
        ans.push_back(temp[temp.size() - 2]);
    }
    //  for(auto x:ans){
    //      cout << x << endl;
    //  }
    return ans;
}

// Driver Code
int main()
{

    // Testcase input
    int testcases;
    cin >> testcases;

    // Looping through all testcases
    while (testcases--)
    {
        int sizeOfArray;
        cin >> sizeOfArray;

        int arr[sizeOfArray];

        // Array input
        for (int index = 0; index < sizeOfArray; index++)
        {
            cin >> arr[index];
        }

        vector<int> ans = largestAndSecondLargest(sizeOfArray, arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
} // } Driver Code Ends