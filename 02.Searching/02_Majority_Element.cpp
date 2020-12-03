// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Searching

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to find majority element in the array
// a: input array
// size: size of input array
int helper1(int arr[], int s)
{
    int m_i = 0, count = 1;
    int i;
    for (i = 0; i < s; i++)
    {
        if (arr[m_i] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count == 0)
        {
            m_i = i;
            count = 1;
        }
    }
    return arr[m_i];
}
int majorityElement(int a[], int size)
{

    // your code here
    int cand = helper1(a, size);
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (cand == a[i])
        {
            c++;
        }
    }
    // cout << cand << endl;
    if (c > size / 2)
    {
        return cand;
    }
    else
    {
        return -1;
    }
}

// { Driver Code Starts.

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
        {
            cin >> arr[i];
        }

        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
// } Driver Code Ends