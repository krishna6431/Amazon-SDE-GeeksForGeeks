// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing. More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exists an integer K, 1 <= K <= N such that,
a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN
You have to process Q queries. In each query you are given two integer L and R, denoting starting and last index of the subarrays respectively.

Example 1:

Input:
N = 8
a[] = {2,3,2,4,4,6,3,2}
Q = 2
Queries = (0,2), (1,3)
Output:
Yes
No
Explanation: For L = 0 and R = 2, a0 = 2,
a1 = 3 and a2 = 2, since they are in the
valid order,answer is Yes.
For L = 1 and R = 3, a1 = 3, a2 = 2 and
a3 = 4, since a1 > a2 and a2 < a4 the
order isn't valid, hence the answer is
No.

*/

/*
// Time Complexity : O(n+q);
// Space Complexity : O(n);


Approach:The problem has multiple queries so for each query the solution should be calculated with least possible time complexity. So create two extra spaces of the length of the original array. For every element find the last index on the left side which is increasing i.e. greater than its previous element and find the element on the right side will store the first index on the right side which is decreasing i.e. greater than its next element. If these value can be calculated for every index in constant time then for every given range the answer can be given in constant time.

Algorithm:
1-->Create two extra spaces of length n,left and right and a extra variable lastptr

2-->Initilize left[0] = 0 and lastptr = 0

3-->Traverse the original array from second index to the end

4-->For every index check if it is greater than the pervious element, if yes then update the lastptr with the current index.

5-->For every index store the lastptr in left[i]

6-->initilize right[N-1] = N-1 and lastptr = N-1

7-->Traverse the original array from second last index to the start

8-->For every index check if it is greater than the next element, if yes then update the lastptr with the current index.

9-->For every index store the lastptr in right[i]

10-->Now process the queries

11-->for every query l, r, if right[l] >= left[r] then print yes else no 

*/

#include <bits/stdc++.h>

using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                            int q);

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++)
        {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v)
        {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
} // } Driver Code Ends

// bool Validity(int *arr,int start,int end){
//     bool inc=false;
//     bool dec=false;
//     int len = end-start+1;
//     if(len < 3 || arr[0] > arr[1]){
//         return false;
//     }
//     for(int i =start ; i < end ; i++){
//         if(arr[i]==arr[i+1] ){
//             return false;
//         }
//         if(arr[i] < arr[i+1]){
//             if(dec==true){
//                 return false;
//             }
//             else{
//                 inc = true;
//             }
//         }
//         if(arr[i]>arr[i+1]){
//             if(dec==false && inc==true){
//                 dec=true;
//             }
//         }
//     }
//     if(inc==true&&dec==true) return true;
//     else return false;
// }
vector<bool> processQueries(int arr[], int N, vector<pair<int, int>> &queries, int q)
{
    // code is written by Krishna
    // Initialize first left index as that index only
    int left[N], right[N];
    left[0] = 0;
    int lastIncr = 0;

    for (int i = 1; i < N; i++)
    {
        // if current value is greater than previous,
        // update last increasing
        if (arr[i] > arr[i - 1])
            lastIncr = i;
        left[i] = lastIncr;
    }

    // Initialize last right index as that index only
    right[N - 1] = N - 1;
    int firstDecr = N - 1;

    for (int i = N - 2; i >= 0; i--)
    {
        // if current value is greater than next,
        // update first decreasing
        if (arr[i] > arr[i + 1])
            firstDecr = i;
        right[i] = firstDecr;
    }
    vector<bool> u;
    for (int i = 0; i < q; i++)
    {
        int l = queries[i].first, r = queries[i].second;
        if (right[l] >= left[r])
            u.push_back(true);
        else
            u.push_back(false);
    }
    return u;
}