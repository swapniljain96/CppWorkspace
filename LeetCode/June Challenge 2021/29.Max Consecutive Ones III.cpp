// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
class Solution
{
public:
    //question boils down to : we have to find the longest subarray that has atmost k zeros
    int longestOnes(vector<int> &a, int k)
    {
        int i = 0, j;
        for (j = 0; j < a.size(); j++)
        {
            if (a[j] == 0)
                k--;
            if (k < 0 and a[i++] == 0)
                k++;
        }
        return j - i;
    }
};