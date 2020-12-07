// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

// Initial function template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool keypair(vector<int> array, int n, int x);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        for (int i = 0; i < n; i++)
            cin >> array[i];
        cout << (keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
// } Driver Code Ends

// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum
bool keypair(vector<int> A, int N, int X)
{
    unordered_map<int, int> m;
    for (int i = 0; i < N; i++)
    {
        if (m.find(X - A[i]) != m.end())
        {
            return true;
        }
        else
        {
            m[A[i]] = i;
        }
    }
    return false;
}
