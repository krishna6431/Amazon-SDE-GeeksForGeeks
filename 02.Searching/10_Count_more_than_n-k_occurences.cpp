// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Searching

// A C++ program to print elements with count more than n/k

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int countOccurence(int arr[], int n, int k);
// Position this line where user code will be pasted.

/* Driver program to test above function */
int main()
{
    int t, k;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        cout << countOccurence(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find element with count more than n/k times
// arr: input array
int countOccurence(int arr[], int n, int k)
{
    // Your code here
    int freq[1000001] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    int c = n / k;
    int ans = 0;
    for (int i = 1; i <= 1000000; i++)
    {
        if (freq[i] > c)
        {
            ans++;
        }
    }

    return ans;
}