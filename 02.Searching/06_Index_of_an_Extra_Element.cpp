//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Searching

#include <bits/stdc++.h>
using namespace std;
int findExtra(int a[], int b[], int n);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> b[i];
        }
        cout << findExtra(a, b, n) << endl;
    }
}// } Driver Code Ends


/*Complete the function below*/
int findExtra(int a[], int b[], int n) {
    // add code here.
    //using binary search
    int l =0,h=n-1;
    int ans = -1;
    while(l<=h){
        int mid = (l+h)/2;
        if(a[mid] == b[mid]){
            l = mid+1;
        }
        else{
            ans = mid;
            h = mid - 1;
        }
    }
    return ans;
}