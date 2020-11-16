//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array

#include<bits/stdc++.h>
using namespace std;
int thirdLargest(int a[],int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cout<<thirdLargest(a,n)<<endl;
    }
}  

int thirdLargest(int arr[], int n)
{
    if(n==1 || n==2){
        return -1;
    }
    int i, j;  
    for (i = 0; i < 3; i++){
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])  {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return arr[n-3];  
}
