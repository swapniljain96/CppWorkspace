/* Problem Description
Given an integer array A, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p.
Input Format
First and only argument is an integer array A.
Output Format
Return 1 if any such integer p is found else return -1.
Example Input
Input 1:
 A = [3, 2, 1, 3]
Input 2:
 A = [1, 1, 3, 3]
Example Output
Output 1:
 1
Output 2:
 -1
Example Explanation
Explanation 1:
 For integer 2, there are 2 greater elements in the array. So, return 1.
Explanation 2:
 There is no such integer exists.
  */
int Solution::solve(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    if (a[n - 1] == 0)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1]) //like if 4 5 6 6 6 6 so to handle this case
        {
            if (a[i] == n - i - 1) //this is our main logic to count the number between that position
                return 1;          // and end , bcoz we sort the array so we got number of elements greater then
        }                          //  that number by just simply doing n-i-1
    }
    return -1;
}
