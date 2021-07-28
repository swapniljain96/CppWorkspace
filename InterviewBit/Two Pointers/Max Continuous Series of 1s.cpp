/* You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index. */

vector<int> Solution::maxone(vector<int> &a, int m)
{
    int n = a.size();
    int currLeft = 0, currRight = 0; //Indexes for the Current Window
    int bestLeft = 0, bestRight = 0; // Indexes for the Best Window
    int count0 = 0;
    vector<int> result;

    while (currRight < n)
    {

        if (count0 <= m)
        {
            if (a[currRight] == 0)
                count0++;               // Including new zeroes in the window.
            currRight++;
        }

        if (count0 > m)
        {
            // Travelling till we find the leftmost zero to discard it from the window
            if (a[currLeft] == 0)
                count0--;
            currLeft++;
        }

        if (currRight - currLeft > bestRight - bestLeft)
        {
            bestLeft = currLeft;
            bestRight = currRight;
        }
    }

    for (int i = bestLeft; i < bestRight; i++)
    {
        result.push_back(i);
    }
    return result;
}
