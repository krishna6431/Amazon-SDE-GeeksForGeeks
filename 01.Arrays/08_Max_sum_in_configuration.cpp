//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array

// Problem Statement :
/*
Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

Example 1:

Input:
N = 4
A[] = {8,3,1,2}
Output: 29
Explanation: Above the configuration
possible by rotating elements are
3 1 2 8 here sum is 3*0+1*1+2*2+8*3 = 29
1 2 8 3 here sum is 1*0+2*1+8*2+3*3 = 27
2 8 3 1 here sum is 2*0+8*1+3*2+1*3 = 17
8 3 1 2 here sum is 8*0+3*1+1*2+2*3 = 11
Here the max sum is 29 

*/

/*
// Time Complexity : O(n);
// Space Complexity : O(1);

Approach: The basic approach is to calculate the sum of new rotation from the previous rotations. This brings up a similarity where only the multipliers of first and last element change drastically and the multiplier of every other element increases or decreases by 1. So in this way, the sum of next rotation can be calculated from the sum of present rotation.

Algorithm: 
    1. The idea is to compute the value of a rotation using values of previous rotation. When an array is rotated by one, following changes happen in sum of i*arr[i].
    2. Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is added to current value.
    3. Multipliers of other terms is decremented by 1. i.e., (cum_sum - arr[i-1]) is subtracted from current value where cum_sum is sum of all numbers
*/

#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{   
    // code is written by krishna
    int c_sum = 0;
    for(int i =0 ; i < n ; i++){
        c_sum+=arr[i];
    }
    int c_val=0;
    for(int i =0 ; i < n ; i++){
        c_val += (arr[i]*i);
    }
    int ans = c_val;
    for(int i =1 ; i < n ; i++){
        int n_val = c_val -(c_sum - arr[i-1]) + arr[i-1]*(n-1);
        c_val = n_val;
        ans = max(ans,n_val);
    }
    return ans;
}