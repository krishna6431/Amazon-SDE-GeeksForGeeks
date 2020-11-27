//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Hashing

//using Sliding Window , Two Pointer , and Hash Table
//Hard Level Problem

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1" 
string smallestWindow (string str, string pat){
    // Your code here
    int l1 = str.size();
    int l2 = pat.size();
    
    if(l1 < l2){
        return "-1";
    }
    
    int map_str[256]={0};
    int map_pat[256]={0};
    
    for(int i = 0 ; i < l2 ; i++){
        map_pat[pat[i]]++;
    }
    
    int start = 0 , start_index = -1 , min_len = INT_MAX;
    
    int c = 0;
    
    for(int j = 0 ; j < l1 ; j++){
        map_str[str[j]]++;
        if(map_pat[str[j]] != 0 && map_str[str[j]] <= map_pat[str[j]]){
            c++;
        }
        if(c==l2){
            while(map_str[str[start]] > map_pat[str[start]] || map_pat[str[start]]==0){
                if(map_str[str[start]] > map_pat[str[start]]){
                    map_str[str[start]]--;
                }
                start++;
            }
            
            int window_size = j - start + 1;
            if(min_len > window_size){
                min_len = window_size;
                start_index = start;
            }
        }
    }
    
    if(start_index == -1){
        return "-1";
    }
    else{
        return str.substr(start_index,min_len);
    }  
}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
