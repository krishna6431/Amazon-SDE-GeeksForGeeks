// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Array

// Problem Statement :
/*
Given two sorted arrays A and B of size M and N respectively. Each array contains only distinct elements but may have
some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end
of any of the two arrays. We can switch from one array to another array only at the common elements. Note: Only one
repeated value is considered in the valid path sum.


Example 1:

Input:
M = 5, N = 4
A[] = {2,3,7,10,12}
B[] = {1,5,7,8}
Output: 35
Explanation: The path will be 1+5+7+10+12
= 35.

*/

// Approach :
// Time Complexity : O(m+n);
// Space Complexity : O(1);
/*
Algorithm:

1--> Create some variables, result, sum1, sum2. Initialize result as 0. Also initialize two variables sum1 and sum2 as
0. Here sum1 and sum2 are used to store sum of element in ar1[] and ar2[] respectively. These sums are between two
common points. 2--> Now run a loop to traverse elements of both arrays. While traversing compare current elements of
array 1 and array 2 in the following order. 1--> If current element of array 1 is smaller than current element of array
2, then update sum1, else if current element of array 2 is smaller, then update sum2. 2--> If the current element of
array 1 and array 2are same, then take the maximum of sum1 and sum2 and add it to the result. Also add the common
element to the result. 2--> This step can be compared to the merging of two sorted arrays, If the smallest element of
the two current array indices is processed then it is guaranteed that if there is any common element it will be
processed together.So the sum of elements between two common elements can be processed.
*/

#include <bits/stdc++.h>
using namespace std;

int max_path_sum(int[], int[], int, int);

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;
        fflush(stdin);
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];
        int result = max_path_sum(a, b, N, M);
        cout << result << endl;
    }
}

// } Driver Code Ends

/*You are required to complete this method*/
int max_path_sum(int A[], int B[], int l1, int l2)
{
    // Code is Written by Krishna
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0, sum = 0;

    while (i < l1 && j < l2)
    {

        if (i < l1 && A[i] < B[j])
        {
            sum1 += A[i];

            i++;
        }

        if (j < l2 && B[j] < A[i])
        {
            sum2 += B[j];

            j++;
        }

        if (A[i] == B[j])
        {
            sum1 += A[i++];
            sum2 += B[j++];

            if (sum1 == sum2)
                sum += sum1;
            else
                sum += max(sum1, sum2);

            sum1 = 0;
            sum2 = 0;
        }
    }

    while (i < l1)
    {
        sum1 += A[i++];
    }

    while (j < l2)
    {
        sum2 += B[j++];
    }

    sum += max(sum1, sum2);
    return sum;
}
