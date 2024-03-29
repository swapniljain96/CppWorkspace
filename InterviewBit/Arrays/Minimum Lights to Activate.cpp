/* Problem Description
There is a corridor in a Jail which is N units long. Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.
All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].
Initially all lights are off.
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.
Problem Constraints
1 <= N <= 1000
1 <= B <= 1000
Input Format
First argument is an integer array A where A[i] is either 0 or 1.
Second argument is an integer B.
Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.
Example Input
Input 1:
A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3

Input 2:
A = [ 0, 0, 0, 1, 0].
B = 3

Example Output
Output 1:

2
Output 2:

-1
Example Explanation
Explanation 1:
In the first configuration, Turn on the lights at 3rd and 8th index.
Light at 3rd index covers from [ 1, 5] and light at 8th index covers [ 6, 8].

Explanation 2:
In the second configuration, there is no light which can light the first corridor. */

int Solution::solve(vector<int> &a, int b)
{
    int n = a.size();
    int cnt = 0;                //initial count is zero
    for (int i = 0; i < n; i++) // here for every i we check if its window contain the bulb or not
    {
        int flag = 0;
        for (int j = i + b - 1; j >= i - b + 1; j--) //here we create a window of leftmost and rightmost
        {                                            // and check from left I buld found then update the value of i
            if (a[j] == 1)
            {
                cnt++;
                flag = 1;
                i = j + b; //here we update the value of i(our upper loop:1st pointer) with "b"  if buld found
                break;     // so that our i will directly jump to start of non-light cover area
            }
        }
        if (flag == 0) //if bulb not found in the array then return -1;
            return -1;
    }
    return cnt;
}