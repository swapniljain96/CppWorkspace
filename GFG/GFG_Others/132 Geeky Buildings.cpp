/* There are N buildings in Linear Land. They appear in a linear line one after the other and their heights are given in the array arr[]. Geek wants to select three buildings in Linear Land and remodel them as recreational spots. The third of the selected building must be taller than the first and shorter than the second.
Can geek build the three-building recreational zone? 

Example 1:

Input:
N = 6
arr[] = {4, 7, 11, 5, 13, 2}
Output:
True
Explanation:
[4, 7, 5] fits the condition. 
Example 2:

Input:
N = 4
arr[] = {11, 11, 12, 9}
Output:
False
Explanation:
No 3 buildings fit the given condition. 

Your Task:
You don't need to read input or print anything. Complete the function recreationalSpot() which takes the array arr[] and its size N as input parameters and returns a boolean value based on whether his building selection was successful or not.
Note: The generated output will be "True" or "False".


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 104
1 ≤ arr[i] ≤ 105 */

class Solution
{
public:
    bool recreationalSpot(int arr[], int n)
    {
        if (N < 3)
        {
            return false;
        }

        // Stores prefix min array
        int preMin[N];
        preMin[0] = arr[0];

        // Iterate over the range [1, N-1]
        for (int i = 1; i < N; i++)
        {
            preMin[i] = min(preMin[i - 1], arr[i]);
        }

        // Stores the element from the
        // ending in increasing order
        stack<int> stack;

        // Iterate until j is greater than
        // or equal to 0
        for (int j = N - 1; j >= 0; j--)
        {

            // If current array element is
            // greater than the prefix min
            // upto j
            if (arr[j] > preMin[j])
            {

                // Iterate while stack is not
                // empty and top element is
                // less than or equal to preMin[j]

                while (!stack.empty() && stack.top() <= preMin[j])
                {
                    // Remove the top element
                    stack.pop();
                }

                // If stack is not empty and top
                // element of the stack is less
                // than the current element
                if (!stack.empty() && stack.top() < arr[j])
                {
                    return true;
                }
                // Push the arr[j] in stack
                stack.push(arr[j]);
            }
        }
        // If none of the above case
        // satify then return "No"
        return false;
    }
};