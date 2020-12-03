// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Searching

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends

// User function Template for C++

double MedianOfArrays(vector<int> &arr, vector<int> &brr)
{
    // Your code goes here
    if (brr.size() < arr.size())
    {
        return MedianOfArrays(brr, arr);
    }
    int x = arr.size();
    int y = brr.size();
    int low = 0;
    int high = x;
    while (low <= high)
    {
        int part1 = (low + high) / 2;
        int part2 = (x + y + 1) / 2 - part1;

        // check corner for first array
        int maxPart1Left = (part1 == 0) ? INT_MIN : arr[part1 - 1];
        int minPart1Right = (part1 == x) ? INT_MAX : arr[part1];

        // check corner for second array
        int maxPart2Left = (part2 == 0) ? INT_MIN : brr[part2 - 1];
        int minPart2Right = (part2 == y) ? INT_MAX : brr[part2];

        if (maxPart1Left <= minPart2Right && maxPart2Left <= minPart1Right)
        {
            if ((x + y) % 2 == 0)
            {
                return (double)(max(maxPart1Left, maxPart2Left) + min(minPart1Right, minPart2Right)) / 2;
            }
            else
            {
                return (double)max(maxPart1Left, maxPart2Left);
            }
        }
        else if (maxPart1Left > minPart2Right)
        {
            high = part1 - 1;
        }
        else
        {
            low = part1 + 1;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin >> array1[i];
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin >> array2[i];
        cout << MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends