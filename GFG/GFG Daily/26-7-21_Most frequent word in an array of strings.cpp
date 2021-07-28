/* Given an array arr containing N words consisting of lowercase characters. Your task is to find the most frequent word in the array. If multiple words have same frequency, then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.

Example 1:

Input:
N = 3
arr[] = {geeks,for,geeks}
Output: geeks
Explanation: "geeks" comes 2 times.
Example 2:

Input:
N = 2
arr[] = {hello,world}
Output: world
Explanation: "hello" and "world" both
have 1 frequency. We print world as
its first occurence comes last in the
input array.
Your Task:
Complete mostFrequentWord function which takes array of strings and its length as arguments and returns the most frequent word. The printing is done by the driver code.

Expected Time Complexity: O(N * WORD_LEN).
Expected Auxiliary Space: O(N * WORD_LEN).

Constraints:
1 <= N <= 50000
1 <= |each string| <= 50
Sum of length of every string does not exceed 5*105 */

class Solution
{
public:
    string mostFrequentWord(string arr[], int n)
    {
        map<string, int> m;
        map<string, int> ocur;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
            if (!ocur[arr[i]])
            {
                ocur[arr[i]] = i + 1;
            }
        }

        // Traverse through map to find the candidate
        // with maximum votes.
        int maxValueInMap = 0;
        string winner;

        for (auto entry : m)
        {
            string key = entry.first;
            int val = entry.second;
            if (val > maxValueInMap)
            {
                maxValueInMap = val;
                winner = key;
            }

            // If there is a tie, pick lexicographically
            // smaller.
            else if (val == maxValueInMap &&
                     ocur[winner] < ocur[key])
                winner = key;
        }
        return winner;
    }
};