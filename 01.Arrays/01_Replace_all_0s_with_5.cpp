//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array

// Problem Statement :
/*
You are given an integer N. You need to convert all zeroes of N to 5.

Example 1:

Input:
N = 1004
Output: 1554
Explanation: There are two zeroes in 1004
on replacing all zeroes with "5", the new
number will be "1554".

*/

//Approach :
// Time Complexity : O(k);
// Space Complexity : O(1);
/*
Algorithm: 
    1.Check a base case when the number is 0 return 5, for all other cases form a recursive function.
    2.The function (solve(int n))can be defined as follows, if the number passed is 0 then return 0, else extract the 3.last digit i.e. n = n/10 and remove the last digit. If the last digit is zero the assign 5 to it.
    4.Now return the value by calling the recursive function for n, i.e return solve(n)*10 + digit.
    5.print the answer.
*/


#include <bits/stdc++.h>
using namespace std;

int convertRec(int n)
{
    //Code is Written By Krishna
    if (n == 0)
        return 0;
    int d = n % 10;
    if (d == 0)
        d = 5;
    return convertRec(n / 10) * 10 + d;
}
int convert(int n)
{
    if (n == 0)
        return 5;
    else
        return convertRec(n);
}
int main()
{
    int n = 10005501;
    cout << convert(n);
    return 0;
}
// Thank You So Much
