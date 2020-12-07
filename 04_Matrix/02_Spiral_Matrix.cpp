// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : Matrix

#include <iostream>
using namespace std;

#define SIZE 105

void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]);

int main()
{
    int T = 0;

    scanf("%d", &T);

    while (T--)
    {
        int m, n;
        scanf("%d", &m);
        scanf("%d", &n);
        int ar[SIZE][SIZE] = {{0}};
        int i = 0;
        int j = 0;
        int row = 0;
        int col = 0;

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &ar[i][j]);
            }
        }

        spirallyTraverse(m, n, ar);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// Complete this function
void spirallyTraverse(int n, int m, int arr[SIZE][SIZE])
{
    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    int count = 0;
    while (sr <= er && sc <= ec)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout << arr[sr][i] << " ";
            count++;
        }
        sr++;
        if (count == n * m)
            break;

        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][ec] << " ";
            count++;
        }
        ec--;
        if (count == n * m)
            break;

        for (int i = ec; i >= sc; i--)
        {
            cout << arr[er][i] << " ";
            count++;
        }
        er--;
        if (count == n * m)
            break;

        for (int i = er; i >= sr; i--)
        {
            cout << arr[i][sc] << " ";
            count++;
        }
        sc++;
        if (count == n * m)
            break;
    }
}
