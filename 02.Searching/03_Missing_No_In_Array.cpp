//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Searching
#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n ;
	    cin >> n;
	    int sum = (n*(n+1))/2;
	    int s =0 ;
	    for(int i =0 ; i < n-1 ; i++){
	        int temp ;
	        cin >> temp ;
	        s+=temp;
	    }
	    
	    cout << sum-s << endl;
	}
	
	return 0;
}