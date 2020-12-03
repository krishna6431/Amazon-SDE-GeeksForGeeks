// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : String

#include <bits/stdc++.h>
using namespace std;

string convertToRoman(int);

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        cout << convertToRoman(N);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/*you are required to complete
this function*/

// n :given number that you are require to convert
string convertToRoman(int n)
{
    // Your code here
    string ans;
    int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = 12;
    while (n > 0)
    {
        int d = n / num[i];
        n = n % num[i];
        while (d--)
        {
            ans.append(sym[i]);
        }
        i--;
    }
    return ans;
}