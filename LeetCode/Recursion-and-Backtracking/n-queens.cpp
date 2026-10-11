/*
 * Problem: N-Queens
 * Question: https://leetcode.com/problems/n-queens/
 *
 * Revision: Place one queen per row. For every column, verify that the row,
 * column, and diagonals contain no queen, then place the queen, recurse to the
 * next row, and remove it while backtracking. Record the board after all rows
 * have been filled.
 *
 * Time: O(n! * n) for this implementation's O(n) placement checks
 * Auxiliary space: O(n^2), excluding the output
 */

class Solution {
private:
vector<vector<string>> ans;

void buildBoard(vector<vector<char>> &board)
{
    int n = board.size();
    vector<string> config;

    for(int i = 0; i < n; i++)
    {
        string s = "";

        for(int j = 0; j < n; j++)
            s += board[i][j];

        config.push_back(s);
    }

    ans.push_back(config);
    return;
}

bool canPlaceRow(int row, int n, vector<vector<char>> &board)
{
    for(int col = 0; col < n; col++)
    {
        if(board[row][col] == 'Q')
            return false;
    }

    return true;
}

bool canPlaceColumn(int col, int n, vector<vector<char>> &board)
{
    for(int row = 0; row < n; row++)
    {
        if(board[row][col] == 'Q')
            return false;
    }

    return true;
}

bool canPlaceDiagonally(int currRow, int currCol, int n, vector<vector<char>> &board)
{
    int row = currRow, col = currCol;

    while(row >= 0 && col >= 0)
    {
        if(board[row][col] == 'Q')
            return false;

        row--;
        col--;
    }

    row = currRow, col = currCol;

    while(row >= 0 && col < n)
    {
        if(board[row][col] == 'Q')
            return false;

        row--;
        col++;
    }
    
    row = currRow, col = currCol;

    while(row < n && col >= 0)
    {
        if(board[row][col] == 'Q')
            return false;

        row++;
        col--;
    }

    row = currRow, col = currCol;

    while(row < n && col < n)
    {
        if(board[row][col] == 'Q')
            return false;

        row++;
        col++;
    }

    return true;
}

bool canPlace(int row, int col, int n, vector<vector<char>> &board)
{
    bool isRow = canPlaceRow(row, n, board);
    bool isCol = canPlaceColumn(col, n, board);
    bool isDiagonal = canPlaceDiagonally(row, col, n, board);

    return isRow && isCol && isDiagonal;
}

void solve(int row, int n, vector<vector<char>> &board)
{
    if(row == n)
    {
        buildBoard(board);
        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(canPlace(row, col, n, board) )
        {
            board[row][col] = 'Q';
            solve(row + 1, n, board);
            board[row][col] = '.';
        }
    }
    
    return;
}

public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<char>> board(n, vector<char> (n, '.'));

        solve(0, n, board);

        return ans;
    }
};
