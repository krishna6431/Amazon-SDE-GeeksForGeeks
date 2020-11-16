//Amazon SDE GeeksForGeeks Problems
//Code is Written by Krishna (krishna_6431)
//Topic : Array
#include <bits/stdc++.h>
using namespace std;

int convertRec(int n)
{

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
