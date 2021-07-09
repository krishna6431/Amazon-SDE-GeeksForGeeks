// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Dynamic Programming

// Problem Statement :
/*
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2
stairs at a time. Count the number of ways, the person can reach the top (order does matter).

Example 1:

Input:
n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways.
Way 1: Climb 2 stairs at a time.
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair
and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs
then 1 stair.
Way 5: Climb 1 stair, then 1 stair and
then 2 stairs.

*/

// Approach :
// Time Complexity : O(N);
// Space Complexity : O(N);

/*

Method 1: The first method uses the technique of recursion to solve this problem.
Approach: We can easily find the recursive nature in the above problem. The person can reach nth stair from either
(n-1)th stair or from (n-2)th stair. Hence, for each stair n, we try to find out the number of ways to reach n-1th stair
and n-2th stair and add them to give the answer for the nth stair. Therefore the expression for such an approach comes
out to be :


ways(n) = ways(n-1) + ways(n-2)


The above expression is actually the expression for Fibonacci numbers, but there is one thing to notice, the value of
ways(n) is equal to fibonacci(n+1).


ways(1) = fib(2) = 1

ways(2) = fib(3) = 2

ways(3) = fib(4) = 3

Method 2: This method uses the technique of Dynamic Programming to arrive at the solution.




Approach: We create a table res[] in bottom up manner using the following relation:


res[i] = res[i] + res[i-j] for every (i-j) >= 0


such that the ith index of the array will contain the number of ways required to reach the ith step considering all the
possibilities of climbing (i.e. from 1 to i).



*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    // Function to count number of ways to reach the nth stair.
    int mod = 1000000007;
    int countWays(int n)
    {
        int dp[n + 1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = ((dp[i - 1]) % mod + (dp[i - 2]) % mod) % mod;
        }
        return dp[n];
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array
    }
    return 0;
}

// Thank U So Much