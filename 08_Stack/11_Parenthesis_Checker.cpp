// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Stacks

// Problem Statement :
/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.


// Approach :
// Time Complexity : O(|X|);
// Space Complexity : O(|X|);

/*

Algorithm: 


1->Declare a character stack S.
2->Now traverse the expression string exp. 
2->If the current character is a starting bracket ('(' or '{' or '[') then push it to stack.
4->If the current character is a closing bracket (')' or '}' or ']') then pop from stack and if the popped character is the matching starting bracket then fine else brackets are not balanced.
5->After complete traversal, if there is some starting bracket left in stack then "not balanced"

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to check if brackets are balanced or not.
    void PrintStack(stack<char> s)
    {
        // If stack is empty
        if (s.empty())
            return;

        // Extract top of the stack
        char x = s.top();

        // Pop the top element
        s.pop();

        // Print the current top
        // of the stack i.e., x
        cout << x << ' ';

        // Proceed to print
        // remaining stack
        PrintStack(s);

        // Push the element back
        s.push(x);
    }
    bool ispar(string x)
    {
        stack<char> stk;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '(' or x[i] == '{' or x[i] == '[')
            {
                stk.push(x[i]);
                // cout << "Stack Element: ";
                // PrintStack(stk);
            }
            else
            {
                if (!stk.empty() && stk.top() == '[' && x[i] == ']')
                {
                    stk.pop();
                }
                else if (!stk.empty() && stk.top() == '{' && x[i] == '}')
                {
                    stk.pop();
                }
                else if (!stk.empty() && stk.top() == '(' && x[i] == ')')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        // PrintStack(stk);
        if (!stk.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        Solution obj;
        if (obj.ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}

//Thank U So Much