//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Searching

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> vec, long long n, long long x){
    int ans = -1;
    int low = 0 , high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(vec[mid]==x){
            return mid;
        }
        else if (vec[mid] > x){
            high = mid -1;
        }
        else{
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    
	    cout << findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}  // } Driver Code Ends