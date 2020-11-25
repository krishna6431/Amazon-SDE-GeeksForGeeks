//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array

#include<bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr, int n);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        vector<int>result = removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}
// } Driver Code Ends


vector<int> removeDuplicate(vector<int>& ve, int n)
{
    // code here
    int h[100]= {0};
    for(int i=0; i<n; i++)
        h[ve[i]]++;
    vector<int>v;
    for(int i=0; i<n; i++)
        if(h[ve[i]]>=1)
        {
            v.push_back(ve[i]);
            h[ve[i]]=0;
        }
    return v;
}


