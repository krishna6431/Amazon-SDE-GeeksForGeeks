// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Hashing

// Problem Statement :
/*
Given a string S consisting of lowercase Latin Letters. Find the first non-repeating character in S.

Example 1:

Input:
N = 5
S = hello
Output: h
Explanation: 'h', 'e' and 'o' are the
non-repeating characters out of which
'h' has the least index.
*/

// Algorithm
// Time Complexity : O(n)
// Space Complexity : O(n)

/*
Approach: Make a count array instead of hash_map of maximum number of characters(256). We can augment the count array by
storing not just counts but also the index of the first time you encountered the character e.g. (3, 26) for 'a' meaning
that 'a' got counted 3 times and the first time it was seen is at position 26. So when it comes to finding the first
non-repeater, we just have to scan the count array, instead of the string. Thanks to Ben for suggesting this approach.

Algorithm :
Make a count_array which will have two fields namely frequency, first occurence of a character.
The size of count_array is '256'.
Traverse the given string using a pointer.
Increase the count of current character and update the occurence.
Now here's a catch, the array will contain valid first occurence of the character which has frequency has unity
otherwise the first occurence keeps updating. Now traverse the count_array and find the character which has least value
of first occurence and frequency value as unity. Return the character
*/

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string find(string s);

// Your code will be place here

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int x;
        cin >> x;
        string s;
        cin >> s;
        int h[26];

        cout << find(s) << "\n";
    }

    return 0;
} // } Driver Code Ends

// User function template for C++

// return the first non-repeating char in S.
// if there's no non-repeating char, return "-1"
string find(string str)
{
    // code written by krishna
    pair<int, int> arr[256];
    for (int i = 0; str[i]; i++)
    {
        arr[str[i]].first++;
        arr[str[i]].second = i;
    }
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
    {
        if (arr[i].first == 1)
        {
            res = min(res, arr[i].second);
        }
    }
    string ans = "";
    if (res == INT_MAX)
    {
        return "-1";
    }
    ans.push_back(str[res]);
    return ans;
}