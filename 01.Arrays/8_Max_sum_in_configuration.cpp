//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array

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