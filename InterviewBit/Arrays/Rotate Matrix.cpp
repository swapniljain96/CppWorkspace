// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// You need to do this in place.
// Note that if you end up using an additional array, you will only receive partial score.
// Example:
// If the array is
// [
//     [1, 2],
//     [3, 4]
// ]
// Then the rotated array becomes:
// [
//     [3, 1],
//     [4, 2]
// ]

//Method 1 : Trasposing+Reversing = 90degree Rotation
void Solution::rotate(vector<vector<int>> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) //IMP start j from i    
        {
            swap(a[i][j], a[j][i]); //Trasposing the array
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(a[i].begin(), a[i].end());
    }
}

//Method 2: by swapping the corner cells
void Solution::rotate(vector<vector<int>> &a)
{
    int n = a.size();
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int tmp = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - j - 1];
            a[n - 1 - i][n - j - 1] = a[j][n - 1 - i];
            a[j][n - 1 - i] = a[i][j];
            a[i][j] = tmp;
        }
    }
}