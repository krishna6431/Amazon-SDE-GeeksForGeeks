//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Hashing

#include <bits/stdc++.h>
using namespace std;

vector<string> findMatchedWords(vector<string> dict,string pattern);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
		    cin>>s[i];
		
		string tt;
		cin>>tt;
		
		vector<string> res = findMatchedWords(s,tt);
        sort(res.begin(),res.end());
		for(int i=0;i<res.size();i++)
		    cout<<res[i]<<" ";
		cout<<endl;
		
	}
}// } Driver Code Ends


/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
bool check(string word , string pattern){
    if(word.size()!=pattern.size()){
        return false;
    }
    char ch[128]={0};
    int len = word.size();
    for(int i = 0 ; i < len ; i++){
        if(ch[pattern[i]]==0){
            ch[pattern[i]] = word[i];
        }
        else if(ch[pattern[i]]!=word[i]){
            return false;
        }
    }
    return true;
}
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       //Your code here
       vector<string>ans;
       for(string word : dict){
           if(check(word,pattern)){
               ans.push_back(word);
           }
       }
       return ans;
}
