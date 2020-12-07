// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Searching
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int x)
{

    if (x == 0 || x == 1)
        return x;
    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

// Driver program
int main()
{
    int x = 19;
    cout << floorSqrt(x) << endl;
    return 0;
}
