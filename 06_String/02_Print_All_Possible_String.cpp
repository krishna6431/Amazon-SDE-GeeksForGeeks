// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : String

// Problem Statement :
/*
Given a string str your task is to complete the function spaceString which takes only one argument the string str and
finds all possible strings that can be made by placing spaces (zero or one) in between them.

For eg .  for the string abc all valid strings will be
                abc
                ab c
                a bc
                a b c

Example 1:

Input:
str = abc
Output: abc$ab c$a bc$a b c$
Example 2:

Input:
str = xy
Output: xy$x y$


*/

// Approach :
// Time Complexity : O(N*2^N);
// Space Complexity : O(N);

/*

The idea is to use recursion and create a buffer that one by one contains all output strings having spaces. We keep
updating the buffer in every recursive call. If the length of the given string is ‘n’ our updated string can have a
maximum length of n + (n-1) i.e. 2n-1. So we create a buffer size of 2n (one extra character for string termination). We
leave 1st character as it is, starting from the 2nd character, we can either fill a space or a character. Thus, one can
write a recursive function like below. Below is the implementation of the above approach:

*/

#include <bits/stdc++.h>
using namespace std;

vector<string> spaceString(char str[]);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        char str[10000];
        cin >> str;
        vector<string> vec = spaceString(str);
        for (string s : vec)
        {
            cout << s << "$";
        }
        cout << endl;
    }
}

void solve(string in, string op, vector<string> &ans)
{
    if (in.size() == 0)
    {
        // cout << op << endl;
        ans.push_back(op);
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(' ');
    op1.push_back(in[0]);
    op2.push_back(in[0]);
    in.erase(in.begin() + 0);
    solve(in, op1, ans);
    solve(in, op2, ans);
    return;
}

vector<string> spaceString(char str[])
{
    vector<string> ans;
    int len = strlen(str);
    string in = "";
    for (int i = 0; i < len; i++)
    {
        in.push_back(str[i]);
    }
    string op = "";
    op.push_back(in[0]);
    in.erase(in.begin() + 0);
    solve(in, op, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

// Thank You So Much