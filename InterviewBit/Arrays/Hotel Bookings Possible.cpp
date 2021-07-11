/* Problem Description
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .
Input Format
First argument is an integer array A containing arrival time of booking.
Second argument is an integer array B containing departure time of booking.
Third argument is an integer C denoting the count of rooms.
Output Format
Return True if there are enough rooms for N bookings else return False.
Return 0/1 for C programs.
Example Input
Input 1:
 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1
Example Output
Output 1:
 0
Example Explanation
Explanation 1:
 At day = 5, there are 2 guests in the hotel. But I have only one room. */

//  Method 1: usinguse one array with tag:'a'/'d' then sort it with user defined compare
bool comp(pair<int, char> a, pair<int, char> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    int n = depart.size();
    vector<pair<int, char>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arrive[i], 'a'});
        v.push_back({depart[i], 'd'});
    }
    sort(v.begin(), v.end(), comp);
    int r = 0, maxr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 'a')
        {
            r++;
            maxr = max(maxr, r);
        }
        else
            r--;
    }
    return maxr <= K;
}

//  Method 2:
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int cnt = 1;
    int i = 0, j = 1;
    while (j < arrive.size())
    {
        if (arrive[j] < depart[i])
            cnt++;
        else
            i++;
        j++;
    }
    return cnt <= K;
}
