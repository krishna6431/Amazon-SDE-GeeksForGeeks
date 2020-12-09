// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows
a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same
time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to
come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly
follows the rule. Each house has a[i] amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(n);


Approach:
1-->Loop for all elements in arr[] and maintain two sums incl and excl where incl = Max sum including the previous
element and excl = Max sum excluding the previous element.

2-->Max sum excluding the current element will be max(incl, excl) and max sum including the current element will be excl
+ current element (Note that only excl is considered because elements cannot be adjacent).

3-->At the end of the loop return max of incl and excl.

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

// } Driver Code Ends
// This a Dynamic Programming Implementation
// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    ll in = arr[0];
    ll out = 0;
    for (ll i = 1; i < n; i++)
    {
        ll temp = in;
        in = max(arr[i] + out, in);
        out = temp;
    }
    return max(in, out);
}

// { Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        ll n;
        cin >> n;
        ll a[n];

        // inserting money of each house in the array
        for (ll i = 0; i < n; ++i)
            cin >> a[i];

        // calling function FindMaxSum()
        cout << FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends