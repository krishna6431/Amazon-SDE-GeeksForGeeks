// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = -1;
        }
    }
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
        }
        if (m.find(sum) == m.end())
        {
            m[sum] = i;
        }
        else
        {
            max_len = max(max_len, i - m[sum]);
        }
    }
    return max_len;
}
