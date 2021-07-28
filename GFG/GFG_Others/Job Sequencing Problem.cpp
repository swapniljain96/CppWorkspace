/* Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500 */

// Method 1: Greedy with loops
class Solution
{
public:
    bool static cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job a[], int n)
    {
        sort(a, a + n, cmp);
        bool done[n] = {0};
        int day = 0, profit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = min(n, a[i].dead - 1); j >= 0; j--)
            {
                if (!done[j])
                {
                    day++;
                    profit += a[i].profit;
                    done[j] = true;
                    break;
                }
            }
        }
        return {day, profit};
    }
};

// Method 2: Greedy with Disjoint Set Union(DSU)
class Solution
{
public:
    // A Simple Disjoint Set Data Structure
    struct DisjointSet
    {
        int *parent;

        DisjointSet(int n)
        {
            parent = new int[n + 1];
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }
        int find(int s)
        {
            if (s == parent[s])
                return s;
            return parent[s] = find(parent[s]);
        }
        void merge(int u, int v)
        {
            parent[v] = u;
        }
    };

    bool static cmp(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    int findMaxDeadline(struct Job arr[], int n)
    {
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, arr[i].dead);
        return ans;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<int> v(2, 0);
        sort(arr, arr + n, cmp);
        int maxDeadline = findMaxDeadline(arr, n);
        DisjointSet ds(maxDeadline);
        for (int i = 0; i < n; i++)
        {
            int availableSlot = ds.find(arr[i].dead);
            if (availableSlot > 0)
            {
                ds.merge(ds.find(availableSlot - 1), availableSlot);
                v[0]++;
                v[1] += arr[i].profit;
            }
        }
        return v;
    }
};