//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : String

#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2)
{
    int arr[26]={0};
    for(int i =0 ; i < str1.size();i++){
        arr[str1[i]-97]++;
    }
    for(int i =0 ; i < str2.size();i++){
            arr[str2[i]-97]--;
        
    }
    int s=0;
    for(int i =0 ; i < 26 ; i++){
        s+=abs(arr[i]);
    }
    return s;
    
}