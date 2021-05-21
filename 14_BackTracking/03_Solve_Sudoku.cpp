// Amazon SDE GeeksForGeeks Problems
// Code is Written by Krishna (krishna_6431)
// Topic : BackTRacking

// Problem Statement :
/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9

*/

// Approach :
// Time Complexity : O(9^N*N);
// Space Complexity : O(N*N);

/*

Method 1: Simple.
Approach: The naive approach is to generate all possible configurations of numbers from 1 to 9 to fill the empty cells. Try every configuration one by one until the correct configuration is found, i.e. for every unassigned position fill the position with a number from 1 to 9. After filling all the unassigned position check if the matrix is safe or not. If safe print else recurs for other cases.

Algorithm: 
1->Create a function that checks if the given matrix is valid sudoku or not. Keep Hashmap for the row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true;
2->Create a recursive function that takes a grid and the current row and column index.
3->Check some base cases. If the index is at the end of the matrix, i.e. i=N-1 and j=N then check if the grid is safe or not, if safe print the grid and return true else return false. The other base case is when the value of column is N, i.e j = N, then move to next row, i.e. i++ and j = 0.
4->if the current index is not assigned then fill the element from 1 to 9 and recur for all 9 cases with the index of next element, i.e. i, j+1. if the recursive call returns true then break the loop and return true.
5->if the current index is assigned then call the recursive function with index of next element, i.e. i, j+1

Method 2: Backtracking. 
Approach: 
Like all other Backtracking problems, Sudoku can be solved by one by one assigning numbers to empty cells. Before assigning a number, check whether it is safe to assign. Check that the same number is not present in the current row, current column and current 3X3 subgrid. After checking for safety, assign the number, and recursively check whether this assignment leads to a solution or not. If the assignment doesn't lead to a solution, then try the next number for the current empty cell. And if none of the number (1 to 9) leads to a solution, return false and print no solution exists.

Algorithm: 
1->Create a function that checks after assigning the current index the grid becomes unsafe or not. Keep Hashmap for a row, column and boxes. If any number has a frequency greater than 1 in the hashMap return false else return true; hashMap can be avoided by using loops.
2->Create a recursive function that takes a grid.
3->Check for any unassigned location. If present then assign a number from 1 to 9, check if assigning the number to current index makes the grid unsafe or not, if safe then recursively call the function for all safe cases from 0 to 9. if any recursive call returns true, end the loop and return true. If no recursive call returns true then return false.
4->If there is no unassigned location then return true

*/

#include <bits/stdc++.h>
using namespace std;
#define N 9
class Solution
{
public:
    bool used_in_row(int grid[N][N], int r, int num)
    {
        for (int col = 0; col < N; col++)
        {
            if (grid[r][col] == num)
            {
                return true;
            }
        }
        return false;
    }

    bool used_in_col(int grid[N][N], int c, int num)
    {
        for (int row = 0; row < N; row++)
        {
            if (grid[row][c] == num)
            {
                return true;
            }
        }
        return false;
    }

    bool used_in_box(int grid[N][N], int box_sr, int box_sc, int num)
    {
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                if (grid[r + box_sr][c + box_sc] == num)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(int grid[N][N], int r, int c, int num)
    {
        return !used_in_row(grid, r, num) && !used_in_col(grid, c, num) &&
               !used_in_box(grid, r - r % 3, c - c % 3, num) && grid[r][c] == 0;
    }

    bool find_unassigned(int grid[N][N], int &r, int &c)
    {
        for (r = 0; r < N; r++)
        {
            for (c = 0; c < N; c++)
            {
                if (grid[r][c] == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        int r, c;
        if (!find_unassigned(grid, r, c))
            return true;

        for (int i = 1; i <= N; i++)
        {
            if (isSafe(grid, r, c, i))
            {
                grid[r][c] = i;

                if (SolveSudoku(grid))
                {
                    return true;
                }
                grid[r][c] = 0;
            }
        }
        return false;
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};
//main function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
}

//Thank U So Much