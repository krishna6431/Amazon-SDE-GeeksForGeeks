// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : String

// Problem Statement :
/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i

*/

// Approach :
// Time Complexity : O(|s|);
// Space Complexity : O(|s|);
/*
separate each word using '.' and then traverse from the last obtained word.
*/

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << reverseWords(s) << endl;
    }
} // } Driver Code Ends

string reverseWords(string s)
{
    // code here
    vector<string> v;
    string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
        {
            v.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    v.push_back(str);
    string ans = "";
    for (int i = v.size() - 1; i > 0; i--)
    {
        ans += v[i];
        ans += ".";
    }
    ans += v[0];
    return ans;
}
// Thank You So Much
