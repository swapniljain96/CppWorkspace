/* Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

Where:

A[i][0] = start time of the ith meeting.
A[i][1] = end time of the ith meeting.
Find the minimum number of conference rooms required so that all meetings can be done.

Problem Constraints
1 <= N <= 10
0 <= A[i][0] < A[i][1] <= 2 * 109

Input Format
The only argument given is the matrix A.
Output Format
Return the minimum number of conference rooms required so that all meetings can be done.

Example Input
Input 1:

 A = [      [0, 30]
            [5, 10]
            [15, 20]
     ]

Input 2:

 A =  [     [1, 18]
            [18, 23]
            [15, 29]
            [4, 15]
            [2, 11]
            [5, 13]
      ]

Example Output
Output 1:

 2
Output 2:

 4

Example Explanation
Explanation 1:

 Meeting one can be done in conference room 1 form 0 - 30.
 Meeting two can be done in conference room 2 form 5 - 10.
 Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
Explanation 2:

 Meeting one can be done in conference room 1 from 1 - 18.
 Meeting five can be done in conference room 2 from 2 - 11.
 Meeting four can be done in conference room 3 from 4 - 15.
 Meeting six can be done in conference room 4 from 5 - 13.
 Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
 Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval. */

//Method 1: by using sorting vector pair of  arrival and departure and count the room.
bool comp(pair<int, char> a, pair<int, char> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int Solution::solve(vector<vector<int>> &a)
{
    vector<pair<int, char>> v;
    for (int i = 0; i < a.size(); i++)
    {
        v.push_back({a[i][0], 'a'});
    }
    for (int i = 0; i < a.size(); i++)
    {
        v.push_back({a[i][1], 'd'});
    }
    sort(begin(v), end(v), comp);
    int ans = 0, res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 'a')
        {
            ans++;
        }
        else
        {
            ans--;
        }
        res = max(res, ans);
    }
    return res;
}

// Method 2: by creating separated arrays of start and end and using 2 pointers
int Solution::solve(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<int> a(n), d(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = arr[i][0];
    }

    for (int i = 0; i < n; i++)
    {
        d[i] = arr[i][1];
    }

    sort(begin(a), end(a));
    sort(begin(d), end(d));

    int plat = 0, res = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (a[i] < d[j])
        {
            plat++;
            i++;
        }
        else
        {
            plat--;
            j++;
        }
        res = max(res, plat);
    }
    return res;
}

// Method 3: by using a map to store the count of rooms
int Solution::solve(vector<vector<int>> &A)
{

    map<int, int> mp;

    for (auto x : A)
    {
        mp[x[0]]++; 
        mp[x[1]]--;
    }
    int sum = 0, cnt = 0;
    for (auto x : mp)
    {
        sum += x.second;
        cnt = max(cnt, sum);
    }
    return cnt;
}
