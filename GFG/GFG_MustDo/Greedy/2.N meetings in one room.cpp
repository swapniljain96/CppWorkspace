/* There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.

Your Task :
You don't need to read inputs or print anything. Complete the function maxMeetings() that takes two arrays start[] and end[] along with their size N as input parameters and returns the maximum number of meetings that can be held in the meeting room.


Expected Time Complexity : O(N*LogN)
Expected Auxilliary Space : O(N)


Constraints:
1 ≤ N ≤ 105
0 ≤ start[i] < end[i] ≤ 105 */

class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    }
    int maxMeetings(int s[], int e[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({s[i], e[i]});
        }
        sort(begin(v), end(v), comp);
        //   for(int i=0;i<v.size();i++)
        //   { cout<<v[i].first<<" "<<v[i].second<<"\n"; }
        int i = 0, j = 1, res = 1;
        while (j < n)
        {
            if (v[i].second < v[j].first)
            {
                res++;
                i = j;
                j++;
            }
            else
            {
                j++;
            }
        }
        return res;
    }
};