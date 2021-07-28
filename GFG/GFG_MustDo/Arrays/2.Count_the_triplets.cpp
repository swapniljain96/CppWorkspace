/* Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
 
Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
â€‹Example 2:

Input: 
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countTriplet() which takes the array arr[] and N as inputs and returns the triplet count

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105 */

class Solution
{
public:
	int countTriplet(int a[], int n)
	{
		sort(a, a + n);					//firstly sort the array
		int cnt = 0;					// initialize counter as 0
		for (int i = n - 1; i > 0; i--) // start from the last element to see usko koi triplet ban raha hau ya nahi
		{
			int j = 0;
			int k = i - 1; // initialize start and end index pointers
			while (j < k)  // i should must be less then j bcoz if [ 1 ,2 , 3 ,4,6] toh ye (3,3) ek triplet count kr lega
			{
				if (a[i] == a[k] + a[j]) // if triplet found than counter++;
				{
					cnt++;
					j++;
					k--;
				}
				else if (a[j] + a[k] < a[i]) // sum if lesse then increase j by 1
				{
					j++;
				}
				else
				{
					k--;
				} // sum if greater then decrease j by 1
			}
		}
		return cnt;
	}
};
