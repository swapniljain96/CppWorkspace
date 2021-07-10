/* Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
Input Format:
The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
Output Format:
Return a 2-d matrix that satisfies the given conditions.
Constraints:
1 <= N, M <= 1000
0 <= A[i][j] <= 1
Examples:
Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]
Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]
*/
// Method 1
void Solution::setZeroes(vector<vector<int>> &a)
{
    int r = a.size();
    int c = a[0].size();
    int col0 = 1; // here we are using our column flag
    for (int i = 0; i < r; i++)
    {
        if (a[i][0] == 0)
            col0 = 0;               // so if any column value is zero then set flag is 0
        for (int j = 1; j < c; j++) // and in updation loop we make that column value 0
        {
            if (a[i][j] == 0)
            {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }
    for (int i = r - 1; i >= 0; i--) // we are using 1st row and 1st cloumn as auxillary space
    {
        for (int j = c - 1; j >= 1; j--) // so we have to start update our array from (n,n) to (0,1)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
        if (!col0)
        {
            a[i][0] = 0;
        } // bcoz for col we use this flag:col0
    }
}

// Method 2: GFG MORE Clear Code that uses both row and col flag
void modifyMatrix(bool mat[R][C])
{
    // variables to check if there are any 0
    // in first row and column
    bool row_flag = false;
    bool col_flag = false;

    // updating the first row and col if 0
    // is encountered
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (i == 0 && mat[i][j] == 0)
                row_flag = true;

            if (j == 0 && mat[i][j] == 0)
                col_flag = true;

            if (mat[i][j] == 0)
            {

                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }
    }

    // Modify the input matrix mat[] using the
    // first row and first column of Matrix mat
    for (int i = 1; i < R; i++)
    {
        for (int j = 1; j < C; j++)
        {

            if (mat[0][j] == 0 || mat[i][0] == 0)
            {
                mat[i][j] = 0;
            }
        }
    }

    // modify first row if there was any 1
    if (row_flag == true)
    {
        for (int i = 0; i < C; i++)
        {
            mat[0][i] = 0;
        }
    }

    // modify first col if there was any 1
    if (col_flag == true)
    {
        for (int i = 0; i < R; i++)
        {
            mat[i][0] = 0;
        }
    }
}
