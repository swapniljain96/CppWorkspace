/* Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]
A partially filled sudoku which is valid.

 Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Return 0 / 1 ( 0 for false, 1 for true ) for this problem */

int Solution::isValidSudoku(const vector<string> &A)
{
    unordered_map<int, unordered_set<char>> row, col, sec;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].length(); j++)
        {
            if (A[i][j] != '.')
            {
                if (row[i].find(A[i][j]) != row[i].end() || col[j].find(A[i][j]) != col[j].end())
                    return 0;
                int s = (j / 3) + 10 * (i / 3);
                if (sec[s].find(A[i][j]) != sec[s].end())
                    return 0;
                row[i].insert(A[i][j]);
                col[j].insert(A[i][j]);
                sec[s].insert(A[i][j]);
            }
        }
    }
    row.clear();
    col.clear();
    sec.clear();
    return 1;
}
