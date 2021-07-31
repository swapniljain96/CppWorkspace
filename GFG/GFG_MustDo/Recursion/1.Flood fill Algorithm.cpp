/* An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.
 

Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
 

Constraints:
1 <= n <= m <= 100
0 <= pixel values <= 10
0 <= sr <= (n-1)
0 <= sc <= (m-1) */

class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int r, int c, int src)
    {

        if (sr < 0 || sr >= r || sc < 0 || sc >= c || image[sr][sc] != src)
            return;
        //src will have the color/number which we have to change
        //and if our current index don't have that value then
        image[sr][sc] = newColor;                    //simply return bcoz we dont have to change that to newColor
        dfs(image, sr - 1, sc, newColor, r, c, src); //TOP
        dfs(image, sr + 1, sc, newColor, r, c, src); //DOWN
        dfs(image, sr, sc - 1, newColor, r, c, src); //LEFT
        dfs(image, sr, sc + 1, newColor, r, c, src); //RIGHT
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc])
            return image;
        int r = image.size();
        int c = image[0].size();
        int src = image[sr][sc];
        dfs(image, sr, sc, newColor, r, c, src);
        return image;
    }
};