// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

// using sliding window technique;

#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> result = countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

vector<int> countDistinct(int arr[], int n, int k)
{
    // code here.
    unordered_map<int, int> m;
    vector<int> res;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (m[arr[i]] == 0)
        {
            ans++;
            m[arr[i]]++;
        }
        else
        {
            m[arr[i]]++;
            continue;
        }
    }
    res.push_back(ans);
    for (int i = 1; i <= n - k; i++)
    {
        if (m[arr[i - 1]] == 1)
        {
            ans--;
        }
        m[arr[i - 1]] -= 1;
        if (m[arr[i + k - 1]] == 0)
        {
            ans++;
        }
        m[arr[i + k - 1]] += 1;
        res.push_back(ans);
    }
    return res;
}