// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this function*/

int maxLen(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> m;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < n; i++)
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
